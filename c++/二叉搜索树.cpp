#include<iostream>
#include<windows.h>
#include<stack>
#include<queue>
#include<math.h>
using namespace std;
template<class T>
class BSTree;

template <class T>
class BinaryTreeNode// 二叉树结点的构造
{
    friend class BSTree<T>;
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
class BSTree
{
private:
    BinaryTreeNode<T> *root;
public:
    BSTree();
    BinaryTreeNode<T> ** getroot(){return &root;}
    void add(T c);
    void visit(BinaryTreeNode<T> * node);
    void preOrder_recur(BinaryTreeNode<T>* root);
    void preOrder_unrecur();
    void latOrder_unrecur();
    void midOrder_unrecur();
    void leverOrder();
    void outbignode(){
     T m='0';
     bool n=false;
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
                if(n)
        if(S.top()->element<=m)
        {
            cout<<"error"<<endl;
            return;
        }
        n=true;
            S.push(S.top()->getrightchild());
            node = S.top();
        }
        else
        {
        node=S.top();
                if(n)
        if(S.top()->element<=m)
        {
            cout<<"error"<<endl;
            return;
        }
        n=true;
        S.pop();
        }
        }
            else if((S.top()->getrightchild() != NULL) && (S.top()->getrightchild() != node))
            {
                if(n)
        if(S.top()->element<=m)
        {
            cout<<"error"<<endl;
            return;
        }
        n=true;
            S.push(S.top()->getrightchild());
            node = S.top();
            }
            else
            {
        node=S.top();
                if(n)
        if(S.top()->element<=m)
        {
            cout<<"error"<<endl;
            return;
        }
        n=true;
        S.pop();
            }
    }
            cout<<"yes"<<endl;
}
    bool BSTfind(T c)
{
    T data=c;
    if(root==NULL){
            return false;
    }
    else{BinaryTreeNode<T> *q=root;
    while(1)
    {
        if(q->element==data)
        {
            return true;
        }
        else if(q->element<data)
        {
            if(q->rightchild!=NULL)
            {
                q=q->rightchild;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(q->leftchild!=NULL)
            {
                q=q->leftchild;
            }
            else
            {
                return false;
            }
        }
    }

    }

}
    void del(T c){
    if(root==NULL){
        cout<<"The tree is empty!"<<endl;
    }
    else{BinaryTreeNode<T> *q=root;
    BinaryTreeNode<T> *p=root;
    BinaryTreeNode<T> *s=root;
    BinaryTreeNode<T> *r=root;
    while(1)
    {
        if(q->element==c)
        {
            if(p==q)
            {r=q;
                if(root->rightchild)
                {
                q=q->rightchild;
                while(q->leftchild!=NULL)
                {r=q;
                q=q->leftchild;
                }
                }
                if(r==q)
                {
                    root=root->leftchild;
                }
                else if(q==r->rightchild)
                {q->leftchild=root->leftchild;
                    root=root->rightchild;
                }
                else
                {
                r->leftchild=q->rightchild;
                q->leftchild=root->leftchild;
                q->rightchild=root->rightchild;
                root=q;

                }
                delete p;
            }
            else
            {s=q;
                r=q;
                if(q->rightchild)
                {
                q=q->rightchild;
                while(q->leftchild!=NULL)
                {r=q;
                q=q->leftchild;
                }
                }
                if(r==q)
                {
                    if(s==p->leftchild)
                    p->leftchild=s->leftchild;
                    else
                        p->rightchild=s->leftchild;
                }
                else if(q==r->rightchild)
                {
                    if(s==p->leftchild)
                    {
                        q->leftchild=r->leftchild;
                        p->leftchild=p->leftchild->rightchild;
                    }
                    else
                    {
                        q->leftchild=r->leftchild;
                        p->rightchild=p->rightchild->rightchild;
                    }
                }
                else
                {
                    if(s==p->leftchild)
                    {
                r->leftchild=q->rightchild;
                q->leftchild=p->leftchild->leftchild;
                q->rightchild=p->leftchild->rightchild;
                p->leftchild=q;
                    }
                    else
                    {
                r->leftchild=q->rightchild;
                q->leftchild=p->rightchild->leftchild;
                q->rightchild=p->rightchild->rightchild;
                p->rightchild=q;
                    }

                }
                    delete s;
            }
            return;
        }
        else if(q->element<c)
        {
            if(q->rightchild!=NULL)
            {   p=q;
                q=q->rightchild;
            }
            else
            {
                cout<<c<<" not found in the tree!"<<endl;
                return;
            }
        }
        else
        {
            if(q->leftchild!=NULL)
            {p=q;
                q=q->leftchild;
            }
            else
            {
                cout<<c<<" not found in the tree!"<<endl;
                return;
            }
        }
    }

    }

    }
int leafnumber(BinaryTreeNode<T>* root){
    if(root!=NULL)
    {
        int m,n;
       m= leafnumber(root->leftchild);
       n= leafnumber(root->rightchild);
       if(m==-1 && n==-1)
        return 1;
       else if(m==-1 && n>-1)
        return n;
       else if(n==-1 && m>-1)
        return m;
       else
        return m+n;
    }
    return -1;
}
int has2child(BinaryTreeNode<T>* root){
    if(root!=NULL)
    {
        int m,n;
       m= has2child(root->leftchild);
       n= has2child(root->rightchild);
       if(m==-1 && n==-1)
        return 0;
       else if(m==-1 && n>-1)
        return n;
       else if(n==-1 && m>-1)
        return m;
       else
        return m+n+1;
    }
    return -1;
}
int has1child(BinaryTreeNode<T>* root){
    if(root!=NULL)
    {
        int m,n;
       m= has1child(root->leftchild);
       n= has1child(root->rightchild);
       if(m==-1 && n==-1)
        return 0;
       else if(m==-1 && n>-1)
        return 1+n;
       else if(n==-1 && m>-1)
        return 1+m;
       else
        return m+n;
    }
    return -1;
}
int height(BinaryTreeNode<T>* root){
    if(root!=NULL)
    {
        int m,n;
       m= height(root->leftchild);
       n= height(root->rightchild);
       if(m==-1 && n==-1)
        return 1;
       else if(m==-1 && n>-1)
        return n+1;
       else if(n==-1 && m>-1)
        return m+1;
       else
        return m>n?m+1:n+1;
    }
    return -1;
}
int width(BinaryTreeNode<T>* root){
    if(root!=NULL)
    {
        int mm,nn,m,n,height,maxwidth=1,data=1,wei=1;
        mm=width(root->leftchild);
        nn=width(root->rightchild);
       m=mm %10;
       n=nn%10;
        height= m>n?m+1:n+1;
        mm/=10;
        nn/=10;
        for(int i=1;i<height;i++){
            wei*=maxwidth+1;
            data+=(mm%(maxwidth+1)+nn%(maxwidth+1))*wei;
            mm/=maxwidth+1;
            nn/=maxwidth+1;
            maxwidth*=2;
        }
        return data*10+height;
    }
    return 0;
}
char maxnode(BinaryTreeNode<T>* root){
    if(root!=NULL)
    {
        int m,n;
       m= maxnode(root->leftchild);
       n= maxnode(root->rightchild);
        return m>n?m:n>root->element?n:root->element;
    }
    return 0;
}
void changechild(BinaryTreeNode<T>* root){
    if(root!=NULL)
    {  BinaryTreeNode<T>* t=root->leftchild;
    root->leftchild=root->rightchild;
    root->rightchild=t;
       changechild(root->leftchild);
       changechild(root->rightchild);
    }
}
void deleteleaf(BinaryTreeNode<T>* root){
    if(root!=NULL)
    {  if(root->leftchild!=NULL && root->leftchild->leftchild == NULL && root->leftchild->rightchild == NULL)
    {
    delete root->leftchild;
    root->leftchild = NULL;
    }  if(root->rightchild!=NULL && root->rightchild->leftchild == NULL && root->rightchild->rightchild == NULL)
    {
    delete root->rightchild;
    root->rightchild = NULL;
    }
    if(root->leftchild!=NULL)
       deleteleaf(root->leftchild);
       if(root->rightchild!=NULL)
       deleteleaf(root->rightchild);
    }}
bool iscompletetree(BinaryTreeNode<T>* root){

    using std::queue;
    queue<BinaryTreeNode<T>*>nodeQueue;
    queue<int>numberQueue;
    int number=0;
    BinaryTreeNode<T> * pointer=root;
    if(pointer)
        nodeQueue.push(pointer);
        numberQueue.push(0);
    while(!nodeQueue.empty())
    {
        pointer=nodeQueue.front();
        nodeQueue.pop();
        if(pointer->leftchild)
        {
            nodeQueue.push(pointer->leftchild);
            numberQueue.push(number*2+1);
        }
        if(pointer->rightchild)
        {
            nodeQueue.push(pointer->rightchild);
            numberQueue.push(number*2+2);
        }
        number++;
    }
    int a=-1;
    while(!numberQueue.empty()){
        if(numberQueue.front()-a!=1)
            return false;
            a=numberQueue.front();
        numberQueue.pop();
    }
    return true;
   }
};
template <class T>
BSTree<T>::BSTree()
{
    root=NULL;
}
template <class T>
void BSTree<T>::add(T c)//当输入#则代表为空
{
    T data=c;
       BinaryTreeNode<T>*p=new BinaryTreeNode<T> ;
        p->element=data;
    if(root==NULL){
            root=p;
    }
    else{BinaryTreeNode<T> *q=root;
    while(1)
    {
        if(q->element==data)
        {
            cout<<"data is the same as one of the node element!"<<endl;
            delete p;
            return;
        }
        else if(q->element<data)
        {
            if(q->rightchild!=NULL)
            {
                q=q->rightchild;
            }
            else
            {
                q->rightchild=p;
                return;
            }
        }
        else
        {
            if(q->leftchild!=NULL)
            {
                q=q->leftchild;
            }
            else
            {
                q->leftchild=p;
                return;
            }
        }
    }

    }

}
template <class T>
void BSTree<T>::visit(BinaryTreeNode<T>* node)
{
    if(node!=NULL)
    cout<<node->element<<" ";
    else
        cout<<"NULL ";
}
template <class T>
void BSTree<T>::preOrder_recur(BinaryTreeNode<T>* root)
{
    if(root!=NULL)
    {
        visit(root);
        preOrder_recur(root->leftchild);
        preOrder_recur(root->rightchild);
    }
}
template <class T>
void BSTree<T>::preOrder_unrecur()
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
void BSTree<T>::latOrder_unrecur()
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
void BSTree<T>::midOrder_unrecur()
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
void BSTree<T>::leverOrder()
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
    BSTree<char> a;
    int number;
    char c;
    cout<<"输入结点个数:"<<endl;
    cin>>number;
    cout<<"输入各结点值:"<<endl;
    for(int i=0;i<number;i++)
    {
        cin>>c;
        a.add(c);
    }
        while(1)
        {
           cout<<endl<<"请选择您所需的操作："<<endl<<"1.广度优先遍历"<<endl<<"2.递归的先序遍历"<<endl<<"3.非递归的先序遍历"<<endl<<"4.非递归的后序遍历"<<endl<<
           "5.非递归的中序遍历"<<endl<<"6.叶子结点个数"<<endl<<"7.中度为1结点个数"<<endl<<"8.中度为2结点个数"<<endl<<"9.高度"<<endl<<"10.宽度"<<endl<<
           "11.最大元素"<<endl<<"12.换孩子"<<endl<<"13.去叶子"<<endl<<"14.是否为完全二叉树"<<endl<<"15.加结点"<<endl<<"16.删结点"<<endl<<"17.找结点"<<endl;
           cout<<"18.比特定值大的结点排序"<<endl;
    cin>>number;
  switch(number)
    {
    case 1:
       a.leverOrder(); break;
    case 2:
       a.preOrder_recur(*a.getroot()); break;
    case 3:
       a.preOrder_unrecur(); break;
    case 4:
       a.latOrder_unrecur(); break;
    case 5:
       a.midOrder_unrecur(); break;
    case 6:
       cout<<"叶子结点个数："<< a.leafnumber(*a.getroot())<<endl; break;
    case 7:
         cout<<"中度1结点个数："<< a.has1child(*a.getroot())<<endl;break;
    case 8:
         cout<<"中度2结点个数："<< a.has2child(*a.getroot())<<endl;break;
    case 9:
         cout<<"高度："<< a.height(*a.getroot())<<endl;break;
    case 10:
        {
            int hei=a.width(*a.getroot())%10;
        int wid=a.width(*a.getroot())/10;
            cout<<"(";cout<<"高度："<<hei<<endl;
        int maxwid=0,maxwidth=1;
        for(int i=0;i<hei;i++){
                cout<<"第"<<i+1<<"级宽度："<<wid%(maxwidth+1)<<endl;
           maxwid=(maxwid>(wid%(maxwidth+1)))?maxwid:(wid%(maxwidth+1));
           wid/= (maxwidth+1);
        maxwidth*=2;
        }
         cout<<")\n宽度："<<maxwid <<"  "<<endl;break;
        }
    case 11:
        cout<<"最大元素："<<a.maxnode(*a.getroot())<<endl;break;
    case 12:
        a.changechild(*a.getroot());break;
    case 13:
        a.deleteleaf(*a.getroot());break;
    case 14:
       cout<< (a.iscompletetree(*a.getroot())?"是完全二叉树":"不是完全二叉树")<<endl;break;
    case 15:
        {
    cout<<"输入插入结点个数:"<<endl;
    cin>>number;
    cout<<"输入各结点值:"<<endl;
    for(int i=0;i<number;i++)
    {
        cin>>c;
        a.add(c);
    }
    break;

        }
    case 16:
        {
            cout<<"输入删除结点的值"<<endl;
            cin>>c;
            a.del(c);
        }
        break;
    case 17:
        {
            cout<<"输入查找结点的值"<<endl;
            cin>>c;
            cout<<(a.BSTfind(c)?"找到结点！":"未找到结点！")<<endl;
        }
        break;
    case 18:
        a.outbignode();
        break;
    default:
        cout<<"对不起，输入错误，请重新输入"<<endl; break;
    }
        }


}
