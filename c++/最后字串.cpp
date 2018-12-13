#include <iostream>
#include <conio.h>
#include <string>
#include<vector>
using namespace std;
int StrMatching(string& T, string& P) {
int plen =P.length(); int tlen=T.length();
if(tlen<plen) return -1;
int  i=tlen-1,  j=plen-1;
while(i>=0 && j>=0){
         if(T[i]==P[j]) {cout<<i<<" "<<j<<endl;i--; j--;}
         else {cout<<i<<" "<<j<<endl;i=i-j+tlen-2; j=tlen-1; cout<<i<<" "<<j<<endl; } }	 //下一趟比较
 if(j<0) return  i+1;  //匹配成功
else  return -1;    }

int main()
{
    int a;
    string mainstring,sonstring;
    cout<<"输入主串:"<<endl;
    cin>>mainstring;
    cout<<"输入子串:"<<endl;
    cin>>sonstring;
    if((a=StrMatching(mainstring, sonstring))==-1)
    {
        cout<<"未找到指定字符串";
    }
    else
    {
        cout<<"找到字符串,在主串的第"<<a+1<<"位"<<endl;
    };
    getch();
}
