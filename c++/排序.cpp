#include <iostream>
#include <conio.h>
#include <time.h>
#include<cstdlib>
using namespace std;
const int N=20;
void show(int* a,int length=N)
{
    for(int n=0;n<length;n++)
    {
        cout<<a[n]<<" ";
    }
    cout<<endl;
}
void Quicksort1(int* a, int length)
{
    if(length>1)
    {
        int b=a[0];
        int c;
    int head=1;
    int tail=length-1;
    while(tail>=head)
    {
        while(tail+1>head && a[tail]>b)
            tail--;
        while(head<tail+1 && a[head]<=b)
            head++;
            if(head<tail)
            {
        cout<<"swap "<<a[head]<<" and "<<a[tail]<<endl;
        c=a[head];
        a[head]=a[tail];
        a[tail]=c;
        tail--;
        head++;
            }
    }
        show(a,length);
    cout<<"shaft:  "<<a[tail]<<" swap with "<<a[0]<<endl<<endl;
    a[0]=a[tail];
    a[tail]=b;
    Quicksort1(a,tail);
    Quicksort1(a+tail+1,length-tail-1);

    }

}


void Quicksort2(int* a, int length)
{
    if(length>1)
    {
        int b=a[0];
        int c;
    int head=0;
    int tail=length-1;
        while(tail>head)
        {
        while(tail>head && a[tail]>b)
            tail--;
            a[head]=a[tail];
        while(head<tail && a[head]<=b)
            head++;
            a[tail]=a[head];
        }
        a[tail]=b;
        show(a,length);
        cout<<"shift:  "<<tail<<" "<<a[tail]<<endl<<endl;
    Quicksort2(a,tail);
    Quicksort2(a+tail+1,length-tail-1);

    }

}


void Bubblesort(int* a, int length)
{
    int m;
    for(int i=0;i<length;i++)
        for(int j=0;j<length-i-1;j++)
        {
        if(a[j]>a[j+1])
    {
        m=a[j];
        a[j]=a[j+1];
        a[j+1]=m;
        show(a);
    }

        }
}
void Insertsort(int* a, int length)
{
    int m,j;
    for(int i=1;i<length;i++)
    {m=a[i];
        for(j=i-1;j>=0 && a[j]>m;j--)
        {a[j+1]=a[j];
        show(a);
        }
    a[j+1]=m;
    cout<<endl;
        show(a);
    }

}
void Binaryinsertsort(int* a, int length)
{
    int m,left,right,mid,j;
    for(int i=1;i<length;i++)
    {m=a[i];
        for(right=i-1,left=0;right>=left;)
        {mid=(left+right)/2;
        cout<<"left: "<<left<<" "<<a[left]<<" right: "<<right<<" "<<a[right]<<"  mid: "<<mid<<" "<<a[mid]<<endl;
        if(a[mid]<=a[i])
            left=mid+1;
        else
            right=mid-1;
        }
        for(j=i-1;j>right;j--)
            a[j+1]=a[j];
    a[j+1]=m;
        show(a);
    }

}

void Shellsort(int* a, int length)
{
    int d=length/2;
    while (d>=1)
    {cout<<"d:"<<d<<endl;
        for(int k=0;k<d;k++)
        {
            for(int i=k+d;i<length;i+=d)
            {
        cout<<"sort:  ";
                int temp=a[i];
                int j=i-d;
                cout<<a[i]<<"  ";
                while(j>=k && a[j] >temp)
                {
                    cout<<a[j]<<"  ";
                    a[j+d]=a[j];
                    j-=d;
                }
                a[j+d]=temp;
                cout<<endl;
                show(a);
            }
        }
        cout<<endl;
                show(a);
        cout<<endl;
        d=d/2;

    }
}
void Radixsort(int* a,int length)
{
        int* b=new int[length];
        int* c=new int[length];
    for(int i=1;i<1000;i*=10)
    {
        for(int j=0;j<length;j++)
        {
        b[j]=(a[j]/i)%10;
        }
        int n=0;
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<length;k++)
            {
            if(b[k]==j)
                {
                    c[n++]=a[k];
                }
            }
        }
        for(int j=0;j<length;j++)
        {
            a[j]=c[j];
        }
        cout<<"进行模"<<i*10<<"排序："<<endl;
        show(a);
    }
}
void Selectionsort(int* a, int length)
{int min,temp;
    for(int i=0;i<length-1;i++)
    {min=i;
        for(int j=i+1;j<length;j++)
            if(a[min]>a[j])
            min=j;
        cout<<"min:  " <<min<<" "<<a[min]<<",swap with "<<a[i]<<endl;
            temp=a[i];
    a[i]=a[min];
    a[min]=temp;
    show(a);
    }
}
void Siftdown(int* a, int i, int n)
{
    int l=2*i+1,r=2*i+2,min=i;
    if(l<n && a[min]<a[l])
        min=l;
    if(r<n && a[min]<a[r])
        min=r;
    if(min != i)
    {
        int t=a[min];
        a[min]=a[i];
        a[i]=t;
        Siftdown(a,min,n);
    }
}
void BuildHeap(int* a, int n)
{
    int p=n/2-1;
    for(int i=p;i>=0;i--)
        Siftdown(a,i,n);
}
void Heapsort(int* a , int n)
{
    BuildHeap(a,n);
    for(int i=n-1;i>0;i--)
    {cout<<"建堆："<<endl;
        show(a);
        int t=a[0];
        a[0]=a[i];
        a[i]=t;
        cout<<"调整后为："<<endl;
        show(a);
        BuildHeap(a,i);
    }
}
void Merge(int* data, int start,int mid,int end)
{
    int len1=mid-start+1,len2=end-mid;
    int i,j,k;
    int* left =new int[len1];
    int* right = new int[len2];
    cout<<"left:"<<endl;
    for(i=0;i<len1;i++){
        left[i]=data[i+start];
    cout<<left[i]<<" ";

    }
    cout<<endl<<"right:"<<endl;
    for(i=0;i<len2;i++){
        right[i]=data[i+mid+1];
    cout<<right[i]<<" ";

    }
    cout<<endl;
    i=0,j=0;
    for(k=start;k<end;k++)
    {
        if(i==len1 || j == len2)
            break;
        if(left[i]<=right[j])
            data[k]=left[i++];

        else

            data[k]=right[j++];
    }
    while(i<len1)
        data[k++]=left[i++];
    while(j<len2)
        data[k++]=right[j++];
    delete[] left;
    delete[] right;

}
void Mergesort(int* data, int start,int end)
{
    if(start < end)
    {
        int mid = (start+end)/2;
        Mergesort(data,start,mid);
        Mergesort(data,mid+1,end);
    cout<<"排序后"<<endl;
        show(data);
        Merge(data,start,mid,end);
    }
}
int main()
{
    srand(time(0));
    int* ary =new int[N];
        cout<<"原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"快速排序1："<<endl;
    Quicksort1(ary,N);
        cout<<"快速排序1后数组："<<endl;
    show(ary);

        cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"快速排序2："<<endl;
    Quicksort2(ary,N);
        cout<<"快速排序2后数组："<<endl;
    show(ary);


              cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"冒泡排序："<<endl;
    Bubblesort(ary,N);
        cout<<"冒泡排序后数组："<<endl;
    show(ary);


        cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"直接插入排序："<<endl;
    Insertsort(ary,N);
        cout<<"直接插入排序后数组："<<endl;
    show(ary);
        cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"折半插入排序："<<endl;
    Binaryinsertsort(ary,N);
        cout<<"折半插入排序后数组："<<endl;
    show(ary);
        cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"希尔排序："<<endl;
    Shellsort(ary,N);
        cout<<"希尔排序后数组："<<endl;
    show(ary);
        cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"选择排序："<<endl;
    Selectionsort(ary,N);
        cout<<"选择排序后数组："<<endl;
    show(ary);
        cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"堆排序："<<endl;
    Heapsort(ary,N);
        cout<<"堆排序后数组："<<endl;
    show(ary);
        cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"归并排序："<<endl;
    Mergesort(ary,0,N-1);
        cout<<"归并排序后数组："<<endl;
    show(ary);
        cout<<"\n\n\n\n\n原数组："<<endl;
    for(int n=0;n<N;n++)
    {
        ary[n]=rand()%1000;
    }
    show(ary);
        cout<<"基数排序："<<endl;
    Radixsort(ary,N);
        cout<<"基数排序后数组："<<endl;
    show(ary);

}
