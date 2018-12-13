#include <iostream>
#include <string>
using namespace std;
template <class T>
class Stack{
public:
	Stack(int MaxStackSize=10);
	~Stack() { delete [] stack;}
	bool IsEmpty() const {return top==-1;}
	bool IsFull() const {return top==MaxTop;}
	T Top() const;
	Stack<T>& Add(const T& x);
	Stack<T>& Del(T& x);
	Stack<T>& Prt();
	void MakeEmpty(){top=-1;} //清空栈
private:
	int top;//栈顶
	int MaxTop;//最大的栈顶值
	T *stack;//堆栈元素数组
};
template<class T>
Stack<T>::Stack(int MaxStackSize){
	MaxTop=MaxStackSize-1;
	stack=new T[MaxStackSize];
	top=-1;
}
template<class T>
Stack<T>& Stack<T>::Add(const T& x){
	if(IsFull())
	{cout<<"no memory;"<<endl;return *this;}
	top=top+1;
	stack[top]=x;
	return *this;
}
template<class T>
Stack<T>& Stack<T>::Del(T& x){
	if(IsEmpty())
	{cout<<"no element"<<endl;return *this;}
	x=stack[top];
	top=top-1;
	return *this;
}
template<class T>
Stack<T>& Stack<T>::Prt(){
	if(IsEmpty())
	{cout<<"no element"<<endl;return *this;}
	for(int i=0;i<=top;i++)
    cout<<stack[i]<<"  ";
    cout<<endl;
	return *this;
}
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
            cout<<"栈为空，不能执行出栈操作"<<endl;
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
            cout<<"栈为空，不能执行出栈操作"<<endl;
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
};
int main(){
    Stack<int> sta;
    sta.Add(1);
    sta.Add(2);
    sta.Prt();
    LinkStack<int> st;
    st.Push(1);
    st.Push(2);
    st.Push(4);
    int a;
    st.Pop(a);
    st.print();
    cout<<"a:"<<a<<endl;
}
