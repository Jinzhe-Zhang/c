#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
int main()
{
    int c;
    srand(time(0));
    for(int i=0;i<100;i++)
    {

    c=rand()%100;
    cout<<c<<" ";
    }
}
