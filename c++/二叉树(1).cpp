#include<iostream>
#include<windows.h>
#include<stack>
#include<queue>
using namespace std;
template<class T>
class BinaryTree;

template <class T>
class BinaryTreeNode// 二叉树结点的构造
{
    friend class BinaryTree<T>;
private:
    T element;
    BinaryTreeNode<T> * leftchild;
    BinaryTreeNode<T> * rightchild;
public:
    BinaryTreeNode();//默认构造函数
    BinaryTreeNode(const T& ele,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r);//给定数据值和左右孩子结点的构造函数
    BinaryTreeNode<T> * getleftchild()const;
    BinaryTreeNode<T> * getrightchild()const;
    void addleftchild(BinaryTreeNode<T> *l);
    void addrightchild(BinaryTreeNode<T> *r);
    void addleftchild(T ll);
    void addrightchild(T rr);
};
template <class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
    leftchild=rightchild=NULL;
}
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T&ele,BinaryTreeNode<T> *l,BinaryTreeNode<T>*r)
{
    element=ele;
    leftchild=l;
    rightchild=r;
}
template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getleftchild()const
{
    return leftchild;
}
template <class T>
void BinaryTreeNode<T>::addleftchild(BinaryTreeNode<T> *l)
{
    leftchild = l;
}
template <class T>
void BinaryTreeNode<T>::addrightchild(BinaryTreeNode<T> *r)
{
    rightchild = r;
}
template <class T>
void BinaryTreeNode<T>::addleftchild(T ll)
{
       BinaryTreeNode<T> p=new BinaryTreeNode<T>(ll,NULL,NULL) ;
        leftchild = p;
}
template <class T>
void BinaryTreeNode<T>::addrightchild(T rr)
{
       BinaryTreeNode<T> p=new BinaryTreeNode<T>(rr,NULL,NULL) ;
        rightchild = p;
}


template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getrightchild()const
{
    return rightchild;
}
template <class T>
class BinaryTree
{
private:
    BinaryTreeNode<T> *root;
public:
    BinaryTree();
    BinaryTreeNode<T> ** getroot(){return &root;}
    void creat(BinaryTreeNode<T> *&p);
    void visit(BinaryTreeNode<T> * node);
    void preOrder_recur(BinaryTreeNode<T>* root);
    void preOrder_unrecur();
    void leverOrder();
};
template <class T>
BinaryTree<T>::BinaryTree()
{
    root=NULL;
}
template <class T>
void BinaryTree<T>::creat(BinaryTreeNode<T>*&p)//当输入#则代表为空
{
    char data;
    cin>>data;
    if(data=='#')
        p==NULL;
    else
    {
        p=new BinaryTreeNode<T> ;
        p->element=data;
        creat(p->leftchild);
        creat(p->rightchild);
    }
}
template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T>* node)
{
    if(node!=NULL)
    cout<<node->element<<" ";
    else
        cout<<"NULL ";
}
template <class T>
void BinaryTree<T>::preOrder_recur(BinaryTreeNode<T>* root)
{
    if(root!=NULL)
    {
        visit(root);
        preOrder_recur(root->leftchild);
        preOrder_recur(root->rightchild);
    }
}
template <class T>
void BinaryTree<T>::preOrder_unrecur()
{

   using std::stack;
    stack<BinaryTreeNode<T>*> S;
    S.push(NULL);
    if(root == NULL)
        return;
    S.push(root);
    BinaryTreeNode<T>* node=NULL;
        visit(S.top());
    while(S.top() != NULL)
    {
        if((S.top()->getrightchild() != NULL) && (S.top()->getrightchild() == node) )
            {
        node=S.top();
        S.pop();
            }
        else if(S.top()->getleftchild() != NULL )
        {if (S.top()->getleftchild() != node)
        {
            S.push(S.top()->getleftchild());
            node = S.top();
        visit(S.top());
        }
        else if (S.top()->getrightchild() != NULL)
        {
            S.push(S.top()->getrightchild());
            node = S.top();
        visit(S.top());
        }
        else
        {
        node=S.top();
        S.pop();
        }
        }
            else if((S.top()->getrightchild() != NULL) && (S.top()->getrightchild() != node))
            {
            S.push(S.top()->getrightchild());
            node = S.top();
        visit(S.top());
            }
            else
            {
        node=S.top();
        S.pop();
            }
    }
}
template <class T>
void BinaryTree<T>::leverOrder()
{
    using std::queue;
    queue<BinaryTreeNode<T>*>nodeQueue;
    BinaryTreeNode<T> * pointer=root;
    if(pointer)
        nodeQueue.push(pointer);
    while(!nodeQueue.empty())
    {
        pointer=nodeQueue.front();
        visit(pointer);
        nodeQueue.pop();
        if(pointer->leftchild)
            nodeQueue.push(pointer->leftchild);
        if(pointer->rightchild)
            nodeQueue.push(pointer->rightchild);
    }
}
int main()
{
    BinaryTree<char> a;
    a.creat(*a.getroot());
        int number;
        while(number != 4)
        {
           cout<<"请选择您所需的操作："<<endl<<"1.广度优先遍历"<<endl<<"2.递归的先序遍历"<<endl<<"3.非递归的先序遍历"<<endl<<"4.退出"<<endl;
    cin>>number;
  switch(number)
    {
    case 1:
       a.leverOrder(); break;
    case 2:
       a.preOrder_recur(*a.getroot()); break;
    case 3:
       a.preOrder_unrecur(); break;
    default:
        cout<<"对不起，输入错误，请重新输入"<<endl; break;
    }
        }


}
