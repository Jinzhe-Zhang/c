/*---------------------------------------------------------------------------

蒋轶民制作E-mail：jiangcaiyang123@163.com

最后编辑：年月日:42:29

文件名：main.h

作用：头文件的定义

----------------------------------------------------------------------------*/

/*-----------------------------头文件---------------------------------------*/

#include "dmusici.h"

#include "dmusicf.h"




// 库文件

#pragma comment( lib, "dxguid.lib" )

/*-----------------------------全局变量-------------------------------------*/

IDirectMusicLoader8* g_pLoader                          = NULL;

IDirectMusicSegment8* g_pSegment                   = NULL;

IDirectMusicPerformance8* g_pPerformance           = NULL;

IDirectMusicSegmentState* g_pSegmentState          = NULL;

IDirectMusicAudioPath8* g_pAudioPath               = NULL;

/*------------------------获取控制台窗口句柄----------------------------*/

HWND GetConsoleWindowHandle( void )

{

     TCHAR title[512];

     HWND hWnd;



     GetConsoleTitle( title, sizeof( title ) );

     hWnd = FindWindow( NULL, title );

     return( hWnd );

}

/*------------------------初始化----------------------------------------*/

void Initialize( void )

{

     HWND hConsoleWnd = GetConsoleWindowHandle();

     HRESULT hr;// 结果的句柄



     // 1、初始化COM组件

     hr = CoInitialize( NULL );

     ThrowIfFailed( hr, "1、初始化COM组件错误。" );



     // 2、创建装载器

     hr = CoCreateInstance( CLSID_DirectMusicLoader, NULL,

         CLSCTX_INPROC, IID_IDirectMusicLoader8, (void**)&g_pLoader );

     ThrowIfFailed( hr, "2、创建装载器错误" );



     // 3、创建演艺对象

     hr = CoCreateInstance( CLSID_DirectMusicPerformance, NULL, CLSCTX_INPROC,

         IID_IDirectMusicPerformance8, (void**)&g_pPerformance );

     ThrowIfFailed( hr, "3、创建演艺对象错误" );



     // 4、初始化音频

     hr = g_pPerformance->InitAudio( NULL, NULL, hConsoleWnd,

         DMUS_APATH_DYNAMIC_STEREO, 128, DMUS_AUDIOF_ALL, NULL );

     if ( hr == DSERR_NODRIVER )

     {

         MessageBox( hConsoleWnd, TEXT( "程序无法定位音频硬件，请确认硬件是否支持DirectX 8。" ), TEXT( "4、初始化音频" ), MB_ICONSTOP );

         return;

     }

     else ThrowIfFailed( hr, "初始化音频错误。" );



     return;// 正确返回

}

/*--------------------------释放内存------------------------------------*/

void UnInitialize( void )

{

#define SAFE_RELEASE( p ) if ( p ) { p->Release(); p = NULL; }

     if ( g_pPerformance )

     {

         g_pPerformance->Stop( NULL, NULL, 0, 0 );

         g_pPerformance->CloseDown();

         SAFE_RELEASE( g_pPerformance );

     }

     SAFE_RELEASE( g_pLoader );

}

/*--------------------------载入声音------------------------------------*/

void LoadSound( TString filename )

{

     HRESULT hr;// 结果的句柄



     // 载入文件对象

     hr = g_pLoader->LoadObjectFromFile( CLSID_DirectMusicSegment, IID_IDirectMusicSegment8,

         (WCHAR*)filename.c_str(), (void**)&g_pSegment );

     ThrowIfFailed( hr, "载入文件对象错误。" );

}

/*--------------------------------------------------------------------------*/

bool LoadCWaveFile( CWaveFile& obj )               // 载入CWaveFile数据

{

     HRESULT hr;                                             // 结果的句柄

     if ( obj.GetData() == 0 )

         Throw( "PlayWaveFile：无法获取数据（是不是忘记载入声音文件？）" );



     // 设置DMUS_OBJECTDESC结构

     DMUS_OBJECTDESC desc;

     desc.dwSize = sizeof( DMUS_OBJECTDESC );

     desc.dwValidData = DMUS_OBJ_MEMORY | DMUS_OBJ_CLASS;

     desc.guidClass = CLSID_DirectMusicSegment;

     desc.llMemLength = obj.GetSize();

     desc.pbMemData = obj.SaveData();



     hr = g_pLoader->GetObject( &desc, IID_IDirectMusicSegment8, (void**)&g_pSegment );

     ThrowIfFailed( hr, "PlayWaveFile：无法获取对象。" );



     return true;

}

/*--------------------------------------------------------------------------*/

bool Play( void )                                       // 播放波形文件

{

     //g_pSegment->Download( g_pPerformance );



     if ( !g_pSegment || !g_pPerformance ) return false;// 无法播放

     g_pSegment->Download( g_pPerformance );

     g_pPerformance->PlaySegmentEx( g_pSegment, NULL, NULL,

         DMUS_SEGF_SECONDARY, 0, (IDirectMusicSegmentState **)&g_pSegmentState, NULL, g_pAudioPath );



     return true;

}

/*--------------------------检测声音是否正在播放------------------------*/

bool IsPlaying( void )

{

     if ( !g_pSegment || !g_pPerformance ) return false;

     return g_pPerformance->IsPlaying( NULL, g_pSegmentState ) == S_OK;

}

/*--------------------------加载资源文件-------------------------------*/

bool LoadWaveResource( HMODULE hMod, TString strResName, WORD resID )

{

     HRESULT hr;                                             // 结果的句柄



     // 载入资源

     HRSRC hRes = FindResource( hMod, MAKEINTRESOURCE( resID ), strResName.c_str() );

     if ( hRes == NULL ) Throw( "LoadWaveResource：无法找到资源。" );

     HGLOBAL hGlb = LoadResource( hMod, hRes );

     if ( hGlb == NULL ) Throw( "LoadWaveResource：无法载入资源。" );



     // 设置DMUS_OBJECTDESC结构

     DMUS_OBJECTDESC desc;

     desc.dwSize = sizeof( DMUS_OBJECTDESC );

     desc.dwValidData = DMUS_OBJ_MEMORY | DMUS_OBJ_CLASS;

     desc.guidClass = CLSID_DirectMusicSegment;

     desc.llMemLength = SizeofResource( hMod, hRes );

     desc.pbMemData = (LPBYTE)LockResource( hGlb );



     hr = g_pLoader->GetObject( &desc, IID_IDirectMusicSegment8, (void**)&g_pSegment );

     ThrowIfFailed( hr, "PlayWaveFile：无法获取对象。" );



     return true;

}

/*--------------------------设置全局音量-----------------------------------*/

bool SetGlobalVolume( long decibel )

{

     HRESULT hr;                                             // 结果的句柄

     long volume = decibel * 100;                       // 音量在全局中是分贝的倍

     hr = g_pPerformance->SetGlobalParam( GUID_PerfMasterVolume, &volume, sizeof( decibel ) );

     ThrowIfFailed( hr, "SetGlobalVolume：设置全局声音错误。" );



     return true;

}

/*--------------------------设置音量---------------------------------------*/

bool SetVolume( long decibel, DWORD dwDuration )

{

     HRESULT hr;                                             // 结果的句柄

     long volume = decibel * 100;                       // 音量在全局中是分贝的倍



     // 获得音频的路径，用于设置音量

     /*-------------------------------

     hr = g_pPerformance->GetDefaultAudioPath( &g_pAudioPath );// 获取默认的音频路径

     ThrowIfFailed( hr, "Initialize：无法获取默认音频路径。" );

     /*-------------------------------*/

     IUnknown* pConfig;

     hr = g_pSegment->GetAudioPathConfig( &pConfig );

     if ( hr != DMUS_E_NO_AUDIOPATH_CONFIG )// 无法获取音频的配置

     {

         ThrowIfFailed( hr, "Initialize：在获取音频配置的时候遇到了未知的错误。" );

         hr = g_pPerformance->CreateAudioPath( pConfig, TRUE, &g_pAudioPath );

         ThrowIfFailed( hr, "Initialize：无法创建音频的路径。" );

     }



     // 手动创建一个音频的路径

     hr = g_pPerformance->CreateStandardAudioPath( DMUS_APATH_DYNAMIC_STEREO, 128/*通道数*/, TRUE, &g_pAudioPath );

     ThrowIfFailed( hr, "Initialize：创建音频路径错误。" );

     /*-------------------------------*/



     g_pSegment->Download( g_pAudioPath );



     // 设置音量

     hr = g_pAudioPath->SetVolume( volume, dwDuration );

     ThrowIfFailed( hr, "SetVolume：设置声音错误。" );



     return true;

}

/*--------------------------设置播放的速度（对MIDI有效）-------------------*/

bool SetTempo( int iTempo )

{

     HRESULT hr;

     DMUS_TEMPO_PARAM tempo;

     tempo.dblTempo = iTempo;

     hr = g_pSegment->SetParam( GUID_TempoParam, 0xFFFF, 0, 0, &tempo );

     ThrowIfFailed( hr, "SetTempo：设置参数错误。" );



     // 发送消息

     DMUS_TEMPO_PMSG* pTempo;

     hr = g_pPerformance->AllocPMsg( sizeof(DMUS_TEMPO_PMSG), (DMUS_PMSG**)&pTempo );

     ThrowIfFailed( hr, "SetTempo：分配信息空间错误。" );



     // 设置消息结构体

     ZeroMemory( pTempo, sizeof(DMUS_TEMPO_PMSG) );

     pTempo->dwSize = sizeof(DMUS_TEMPO_PMSG);

     pTempo->dblTempo = iTempo;

     pTempo->dwFlags = DMUS_PMSGF_REFTIME;

     pTempo->dwType = DMUS_PMSGT_TEMPO;

     hr = g_pPerformance->SendPMsg( (DMUS_PMSG*)pTempo );

     ThrowIfFailed( hr, "SetTempo：发送信息错误。" );



     return true;

}

/*--------------------------获取播放的速度（对MIDI有效）-------------------*/

int GetCurrentTempo( void )

{

     HRESULT hr;



     DMUS_TEMPO_PARAM tempo;

     hr = g_pSegment->GetParam( GUID_TempoParam, 0xFFFF, 0, 0, NULL, &tempo );

     ThrowIfFailed( hr, "GetCurrentTempo：获取参数错误。" );

     return int(tempo.dblTempo);

}
