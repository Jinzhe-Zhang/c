#include<iostream>
using namespace std;
int main()
{
    int*a=new int;
    *a=1;
    int*b=a;
    cout<<*b;
}
