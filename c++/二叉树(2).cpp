#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;
template<class T>
class BinaryTree;

template <class T>
class BinaryTreeNode// ���������Ĺ���
{
    friend class BinaryTree<T>;
private:
    T element;
public:
    BinaryTreeNode<T> * leftchild;
    BinaryTreeNode<T> * rightchild;
    BinaryTreeNode();//Ĭ�Ϲ��캯��
    BinaryTreeNode(const T& ele,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r);//��������ֵ�����Һ��ӽ��Ĺ��캯��
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
    void latOrder_unrecur();
    void midOrder_unrecur();
    void cfpm(BinaryTreeNode<T>** root,char* a,char* b );
    void cflm(BinaryTreeNode<T>** root,char* a,char* b );
    void leverOrder();
};
template <class T>
BinaryTree<T>::BinaryTree()
{
    root=NULL;
}
template <class T>
void BinaryTree<T>::creat(BinaryTreeNode<T>*&p)//������#�����Ϊ��
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
    {
    printf("%d",node->element);
    cout<<" ";
    }
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
void BinaryTree<T>::latOrder_unrecur()
{


   using std::stack;
    stack<BinaryTreeNode<T>*> S;
    S.push(NULL);
    if(root == NULL)
        return;
    S.push(root);
    BinaryTreeNode<T>* node=NULL;
    while(S.top() != NULL)
    {
        if((S.top()->getrightchild() != NULL) && (S.top()->getrightchild() == node) )
            {
        node=S.top();
        visit(S.top());
        S.pop();
            }
        else if(S.top()->getleftchild() != NULL )
        {if (S.top()->getleftchild() != node)
        {
            S.push(S.top()->getleftchild());
            node = S.top();
        }
        else if (S.top()->getrightchild() != NULL)
        {
            S.push(S.top()->getrightchild());
            node = S.top();
        }
        else
        {
        node=S.top();
        visit(S.top());
        S.pop();
        }
        }
            else if((S.top()->getrightchild() != NULL) && (S.top()->getrightchild() != node))
            {
            S.push(S.top()->getrightchild());
            node = S.top();
            }
            else
            {
        node=S.top();
        visit(S.top());
        S.pop();
            }
    }
}
template <class T>
void BinaryTree<T>::midOrder_unrecur()
{


   using std::stack;
    stack<BinaryTreeNode<T>*> S;
    S.push(NULL);
    if(root == NULL)
        return;
    S.push(root);
    BinaryTreeNode<T>* node=NULL;
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
        }
        else if (S.top()->getrightchild() != NULL)
        {
        visit(S.top());
            S.push(S.top()->getrightchild());
            node = S.top();
        }
        else
        {
        node=S.top();
        visit(S.top());
        S.pop();
        }
        }
            else if((S.top()->getrightchild() != NULL) && (S.top()->getrightchild() != node))
            {
        visit(S.top());
            S.push(S.top()->getrightchild());
            node = S.top();
            }
            else
            {
        node=S.top();
        visit(S.top());
        S.pop();
            }
    }
}












template <class T>
void BinaryTree<T>::cflm(BinaryTreeNode<T>** root,char* a,char* b )
{
    int i=0;
    char m;
    while(a[i]!=100)
        i++;
        i--;
    m=a[i];
    while(i>=0)
    {
    if(b[i]==m)
    {*root = new BinaryTreeNode <T>;
        (*root)->element= m;
        cout<<root<<"  "<<m+64<<endl;
    a[i]=100;
    b[i]=100;
    cflm(&((*root)->leftchild),a,b);
    cflm(&((*root)->rightchild),a+i+1,b+i+1);
    return;
    }
    if(i==1)
        return;
    a[i]=a[i-1];
    i--;
    }
}







template <class T>
void BinaryTree<T>::cfpm(BinaryTreeNode<T>** root,char* a,char* b )
{
    int i=0;
    char m=a[0];
    while(b[i]!=100)
    {
    if(b[i]==m)
    {*root = new BinaryTreeNode <T>;
        (*root)->element= m;
      //  cout<<root<<"  "<<m<<endl;
    a[i]=100;
    b[i]=100;
    cfpm(&((*root)->leftchild),a,b);
    cfpm(&((*root)->rightchild),a+i+1,b+i+1);
    return;
    }
    a[i]=a[i+1];
    i++;
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
           int iii,i;
    BinaryTree<char> a;
        int number;
        while(1)
        {
           cout<<"��ѡ��������Ĳ�����"<<endl<<"1.�����򴴽�������"<<endl<<"2.�к��򴴽�������"<<endl<<"3.�ǵݹ���������"<<endl<<"4.�ǵݹ�ĺ������"<<endl<<"5.�ǵݹ���������"<<endl;
    cin>>number;
  switch(number)
    {
    case 1:{
           cout<<"���ȣ�"<<endl;
           cin>>iii;
    char aa[100],bb[100];
 cout<<"����"<<endl;
 for(i=0;i<iii;i++)
    scanf("%d",&aa[i]);
 aa[i]=100;
 cout<<"����"<<endl;
 for(i=0;i<iii;i++)
    scanf("%d",&bb[i]);
 bb[i]=100;
 //cout<<*a.getroot()<<endl;
 a.cfpm(a.getroot(),aa,bb);
 //cout<<*a.getroot()<<endl;
 break;}
    case 2:
       {
           cout<<"���ȣ�"<<endl;
           cin>>iii;
    char aa[100],bb[100];
 cout<<"����"<<endl;
 for(i=0;i<iii;i++)
    scanf("%d",&aa[i]);
 aa[i]=100;
 cout<<"����"<<endl;
 for(i=0;i<iii;i++)
    scanf("%d",&bb[i]);
 bb[i]=100;
 a.cflm(a.getroot(),aa,bb); break;
       }
    case 3:
       a.preOrder_unrecur(); break;
    case 4:
       a.latOrder_unrecur(); break;
    case 5:
       a.midOrder_unrecur(); break;
    default:
        cout<<"�Բ��������������������"<<endl; break;
    }
        }


}
