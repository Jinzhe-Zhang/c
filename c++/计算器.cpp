#include <iostream>
#include <string>
#include <stdio.h>
#include<math.h>
using namespace std;

template <class T>
class LinkNode
{
public:
    T data;
    LinkNode<T>*link;
    LinkNode(const T&el,LinkNode<T>*ptr = 0)
    {
        data=el;
        link=ptr;
    };
};
template <class T>
class LinkStack
{
private:
    LinkNode <T> *top;
    int size;

public:
    LinkStack()
    {
        top=NULL;
        size =0;

    }
    ~LinkStack(){
    Clear();}
    void Clear()
    {
        while (top != NULL)
        {
            LinkNode <T> *tmp =top;
            top=top->link;
            delete tmp;

        }
        size =0;

    }
    bool Push(const T item)
    {

        LinkNode <T> *tmp =new LinkNode<T>(item,top);
        top=tmp;
        size++;
        return true;

    }
    bool Pop(T & item)
    {
        LinkNode<T> *tmp;
        if (size ==0)
        {
            return false;

        }
        item = top->data;
        tmp=top->link;
        delete top;
        top =tmp;
        size--;
        return true;
    }
    bool Top(T & item)
    {
        if(size == 0)
        {
            return false;
        }
        item =top->data;
        return true;
    }
    void print()
    {
        LinkNode<T> *tmp =top;
        for(int i=0;i<size;i++)
        {
            cout<<tmp->data<<"  ";
            tmp=tmp->link;
        }
            cout<<endl;
    }
    int paix(char cc,bool in)
    {
        if(cc=='#')
            return 10;
        else if(cc=='(' && in==true || cc==')' && in==false)
            return 11;
        else if(cc==')' && in==true || cc=='(' && in==false)
            return 18;
        else if(cc=='^' && in==true)
            return 17;
        else if((cc=='*' ||cc=='/' ||cc=='%' ) && in==true)
            return 15;
        else if(cc=='^' && in==false)
            return 16;
        else if((cc=='*' ||cc=='/' ||cc=='%' ) && in==false)
            return 14;
        else if((cc=='+' ||cc=='-'  ) && in==true)
            return 13;
        else if((cc=='+' ||cc=='-'  ) && in==false)
            return 12;
            else if(cc>='0' && cc<='9')
                return cc-'0';
            else
                return -1;
    }
    bool text(int* d)
    {   LinkStack<char> invert;
        LinkStack<char> li;
        LinkStack<int> num;
        char c,cc;
        int m,n,o;
        bool numing=false,p=true;
        while(Pop(c))
        {
            invert.Push(c);
        }
        while(invert.Pop(c))
        {
        if(paix(c,false)>9)
        {
            while(li.Pop(cc))
            {
                if(paix(cc,true)>paix(c,false))
                {
                    if((num.Pop(m) && num.Pop(n)) == false)
             return false;
                if(cc=='+')
                    o=m+n;
                else if (cc=='-')
                    o=n-m;
                else if (cc=='*')
                    o=n*m;
                else if (cc=='/')
                {

                    if(m!=0)
                    o=n/m;
                else
                    return false;
                }
                else if (cc=='%')
                {

                    if(m!=0)
                    o=n%m;
                else
                    return false;
                }
                else if (cc=='^')
                {

                    if(m!=0 || n!=0)
                    o=pow(n,m);
                else
                    return false;
                }
                    num.Push(o);
                }
                else if(paix(cc,true)<paix(c,false))
                {
                    li.Push(cc);
                    break;
                }
                else
                {p=false;
                    break;
                }

            }
            if(p)
            {

                    li.Push(c);
            }
                    p=true;
            numing=false;

        }
        else if(paix(c,false)==-1)
            return false;
        else
        {
            if(numing)
            {
                num.Pop(o);
                o=o*10+paix(c,false);
                num.Push(o);
            }
            else
            {
                numing=true;
                num.Push(paix(c,false));
            }
        }
        /*
        invert.print();
        li.print();
        num.print();
        cout<<numing<<"  "<<p<<"####"<<endl;
        */
    }
    while (li.Pop(cc))
    {
        if((num.Pop(m) && num.Pop(n)) == false)
             return false;

                if(cc=='+')
                    o=m+n;
                else if (cc=='-')
                    o=n-m;
                else if (cc=='*')
                    o=n*m;
                else if (cc=='/')
                {

                    if(m!=0)
                    o=n/m;
                else
                    return false;
                }
                else if (cc=='%')
                {

                    if(m!=0)
                    o=n%m;
                else
                    return false;
                }
                else if (cc=='^')
                {

                    if(m!=0 || n!=0)
                    o=pow(n,m);
                else
                    return false;
                }
                    num.Push(o);
    }
    *d=o;
    return true;
    }
};
int main(){
char c;
LinkStack<char> l;
cout<<"输入一个字符串"<<endl;
scanf("%c",&c);
while(c != '\n')
{
l.Push(c);
scanf("%c",&c);
}
int a;
if (l.text(&a))
cout<<"结果为"<<a<<endl;
else
    cout<<"输入错误";
}
