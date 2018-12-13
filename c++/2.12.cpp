#include <iostream>
using namespace std;
int convert(int radix,int num){
    if (radix>1&&radix<10)
   return num>radix ? (num%radix)+convert(radix,num/radix)*10 : num;
   else
   {
    cout<<"radix error!\n";
    return -1;
   }
}
int main(){
    int i,j;
    cout<<"radix:"<<endl;
        cin>>j;
        cout<<"number:"<<endl;
    cin>>i;
    cout<<convert(j,i);
}
