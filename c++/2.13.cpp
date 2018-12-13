#include <iostream>
#include <string>
#include <stdio.h>
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
    bool text()
    {
        LinkStack<char> li;
        char c;
        while(Pop(c))
        {
        if (c == ')')
        {
                   li.Push(')');
        }

        else if (c== ']')
        {
                   li.Push(']');
        }
        else if (c== '}')
        {
                   li.Push('}');
        }
        else if (c== '(')
        {li.Pop(c);
            if (c !=')')
               {
                   return false;
               }
        }

        else if (c=='[')
        {li.Pop(c);
            if ( c !=']')
               {
                   return false;
               }
        }

        else if (c=='{')
        {li.Pop(c);
            if ( c!='}')
               {
                   return false;
               }
        }

        }
        return 0==li.Pop(c);
    }
};
int main(){
char c;
LinkStack<char> l;
cout<<"ÊäÈëÒ»¸ö×Ö·û´®"<<endl;
scanf("%c",&c);
while(c != '\n')
{
l.Push(c);
scanf("%c",&c);
}
if (l.text())
cout<<"·ûºÅÆ¥Åä";
else
    cout<<"·ûºÅ²»Æ¥Åä";
}
