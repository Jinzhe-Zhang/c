#include <iostream>
#include <conio.h>
#include <string>
#include<vector>
using namespace std;
int bfStrMatching(string& T, string& P) {
int  i=0,  j=0;
int plen =P.length(); int tlen=T.length();
if(tlen<plen) return -1;
while(i<tlen && j<plen){
         if(T[i]==P[j]) {cout<<i<<" "<<j<<endl;i++; j++;}
         else {cout<<i<<" "<<j<<endl;i=i-j+1; j=0;  } }	 //下一趟比较
 if(j>=plen) return  i-j;  //匹配成功
else  return -1;    }

int kmpStrMatching(string& T, string& P) {
int  i=0,  j=1,a=0;
int plen =P.length(); int tlen=T.length();
if(tlen<plen) return -1;
vector<int> prepeat(plen,0);
while(j<plen)
{
    while(j<plen && P[j]==P[i])
    {
        a++;
        prepeat[j]=a;
        j++;i++;
    }
    i=0;j++;
}
j=0;i=0;
while(i<tlen && j<plen){
         if(T[i]==P[j]) {cout<<i<<" "<<j<<" equal"<<endl;i++; j++;}
         else {cout<<i<<" "<<j<<" not equal"<<endl;
         if(j!=0) j=prepeat[j-1];
         else{i++;} } }	 //下一趟比较
 if(j>=plen)
 {
 return  i-j;  //匹配成功
 }
else  return -1;    }
int main()
{
    int a;
    string mainstring,sonstring;
    cout<<"输入主串:"<<endl;
    cin>>mainstring;
    cout<<"输入子串:"<<endl;
    cin>>sonstring;
    if((a=bfStrMatching(mainstring, sonstring))==-1)
    {
        cout<<"未找到指定字符串";
    }
    else
    {
        cout<<"找到字符串,在主串的第"<<a+1<<"位"<<endl;
    };
    cout<<"输入主串:"<<endl;
    cin>>mainstring;
    cout<<"输入子串:"<<endl;
    cin>>sonstring;
    if((a=kmpStrMatching(mainstring, sonstring))==-1)
    {
        cout<<"未找到指定字符串";
    }
    else
    {
        cout<<"找到字符串,在主串的第"<<a+1<<"位"<<endl;
    };
    getch();
}
