#include <iostream>
#include <conio.h>
using namespace std;
const int Maxsize=5;
template <class T>
class circlequeue
{
private:
    int front=0,rear=0;
    bool tag=false;
    T data[Maxsize];
public:
    circlequeue(){};
    ~circlequeue(){};
    bool push(const T c)
    {
        cout<<"push "<<c<<endl;
        if(front==rear && tag==true)
        {

            cout<<"Õ»ÂúÁË"<<endl;
            return false;
        }
        else
        {
        data[front]=c;
        front=(front+1)%Maxsize;
        tag=true;
            return true ;
        }
    }
    bool pop(T &c)
    {
        cout<<"pop"<<endl;
        if(front==rear && tag==false)
        {

            cout<<"Õ»¿ÕÁË"<<endl;
            return false;
        }
        else
        {
             c=data[rear];
        rear=(rear+1)%Maxsize;
        tag=false;
        }
            return true;

    }
    void print()
    {int i=rear;
            cout<<"data:"<<endl;
        if(tag)
        {
            cout<<data[(i-1+Maxsize)%Maxsize]<<endl;
            i=(i-1+Maxsize)%Maxsize;
        }
        for(;i!=rear;i=(i-1+Maxsize)%Maxsize)
        {
            cout<<data[(i-1+Maxsize)%Maxsize]<<endl;
        }
    }
};
int main()
{
    int c=0;
    circlequeue <int> a;
    a.pop(c);
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop(c);
    a.push(13);
    a.push(2);
    a.push(5);
    a.push(55);
    a.print();
    cout<<"c:"<<c<<endl;
    getch();
}
