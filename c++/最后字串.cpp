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
         else {cout<<i<<" "<<j<<endl;i=i-j+tlen-2; j=tlen-1; cout<<i<<" "<<j<<endl; } }	 //��һ�˱Ƚ�
 if(j<0) return  i+1;  //ƥ��ɹ�
else  return -1;    }

int main()
{
    int a;
    string mainstring,sonstring;
    cout<<"��������:"<<endl;
    cin>>mainstring;
    cout<<"�����Ӵ�:"<<endl;
    cin>>sonstring;
    if((a=StrMatching(mainstring, sonstring))==-1)
    {
        cout<<"δ�ҵ�ָ���ַ���";
    }
    else
    {
        cout<<"�ҵ��ַ���,�������ĵ�"<<a+1<<"λ"<<endl;
    };
    getch();
}
