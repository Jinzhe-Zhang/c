#include <iostream>
using namespace std;

int max (int a[],int n)
{
    int c;
    if(n==1)
        return a[0];
    else
return a[n-1]> (c = max(a,n-1)) ? a[n-1] : c;
    }

int main () {
    int a[]={1,5,3,-34,2,-5,3,34,-1,9};
    cout<<max(a,10);
}
