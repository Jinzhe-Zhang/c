#include <iostream>
#include <conio.h>
using namespace std;
template <class T>
class LinkNode
{
public:
    T data;
    LinkNode<T>*prev;
    LinkNode<T>*next;
    LinkNode(const T&el = NULL,LinkNode<T>*ptr = 0,LinkNode<T>*pt = 0)
    {
        data=el;
        prev=ptr;
        next=pt;
    };
};
template <class T>
class LinkStack
{
private:
    LinkNode <T> *top;
    LinkNode <T> *rear;

public:
    LinkStack()
    {
        top=rear=new LinkNode<T>();
    }
    ~LinkStack(){
    Clear();}
    void Clear()
    {
        while (top != rear)
        {
            LinkNode <T> *tmp =top;
            top=top->prev;
            delete tmp;

        }

    }
    bool Push(const T item)
    {

        LinkNode <T> *tmp =new LinkNode<T>(item,top);
        top->next=tmp;
        top=tmp;
        return true;

    }
    bool Pop(T & item)
    {
        LinkNode<T> *tmp;
        if (top==rear)
        {
            return false;

        }
        item = top->data;
        tmp=rear->next;
        delete rear;
        rear =tmp;
        return true;
    }
    void print()
    {
        LinkNode<T> *tmp =top;
        while(tmp!=rear)
        {
            cout<<tmp->data<<"  ";
            tmp=tmp->prev;
        }
            cout<<endl;
    }
};
int main()
{int n,i,c;
cout<<"输入n"<<endl;
cin>>n;
    int aa;
LinkStack <int>a[10];
for(i=0;i<n;i++)
{
cin>>c;
if(c>=0 && c<10)
a[c].Push(c);
else
{
    cout<<"第"<<i+1<<"次输入错误,算作无效输入"<<endl;
    i--;
}
}

LinkStack <int>b;
for(i=9;i>=0;i--)
{a[i].print();
    while(a[i].Pop(c))
    b.Push(c);
}
b.print();
    getch();
}
