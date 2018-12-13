#include <iostream>
using namespace std;

void Move (int a[],int n)
{
    int j=0;
    int k=0;
        for(int i=n-1;i>j;)
    {
        if(a[i]<a[n-1])
        {
            while(a[j]<a[n-1])
            {
                j++;
            }
            if(i>j)
            {
                k=a[j];
                a[j]=a[i];
                a[i]=k;
                j++;
            }
            }
                i--;

        }
    }

int main () {
    int a[]={5,6,7,8,5,4,3,6,4,5,0,6,3,5,4,3,5};
    int n=17;
    Move(a,n);
    for(int i=0;i<17;i++)
        cout<<a[i]<<"  ";
}
