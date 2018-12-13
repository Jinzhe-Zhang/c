#include<iostream>
#include<windows.h>
using namespace std;
template<class T>
class BinaryTree;

template <class T>
class BinaryTreeNode// ���������Ĺ���
{
    friend class BinaryTree<T>;
private:
    T element;
    BinaryTreeNode<T> * leftchild;
    BinaryTreeNode<T> * rightchild;
public:
    BinaryTreeNode();//Ĭ�Ϲ��캯��
    BinaryTreeNode(const T& ele,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r);//��������ֵ�����Һ��ӽ��Ĺ��캯��
    BinaryTreeNode<T> * getleftchild()const;
    BinaryTreeNode<T> * getrightchild()const;
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
BinaryTreeNode<T>* BinaryTreeNode<T>::getrightchild()const
{
    return rightchild;
}
template <class T>
class BinaryTree
{
   // friend void menu(BinaryTreeNode<T> *root);
private:
    BinaryTreeNode<T> *root;
public:
    BinaryTree();
    void creat(BinaryTreeNode<T> * &p);
    void visit(BinaryTreeNode<T> * node);
    void preOrder_recur(BinaryTreeNode<T>* root);
    void preOrder_unrecur(BinaryTreeNode<T>* root);
    void leverOrder(BinaryTreeNode<T>*root);
};
template <class T>
BinaryTree<T>::BinaryTree()
{
    root=NULL;
}
template <class T>
void BinaryTree<T>::creat(BinaryTreeNode<T>* &p)//������#�����Ϊ��
{
    char data;
    cin>>data;
    if(data=='#')
        p==NULL;
    else
    {
        p=new BinaryTreeNode;
        p->element=data;
        creat(p->leftchild);
        creat(p->rightchild)
    }
}
template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T>* node)
{
    cout<<node->element<<" "<<endl;
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
void BinaryTree<T>::preOrder_unrecur(BinaryTreeNode<T>* root)
{
    using std::stack;
    stack<BinaryTreeNode<T>*> S;
    S.push(NULL);
    if(root == NULL)
        return;
    S.push(root);
    while(S.front() != NULL)
    {
        BinaryTreeNode<T>* node = S.top();
        S.pop();
        Visit(node);
        if(node->getRightChild() != NULL)
            S.push(node->getrightChild());
        if(node->getLeftChild() != NULL)
            S.push(node->getleftChild());
    }
}
template <class T>
void BinaryTree<T>::leverOrder(BinaryTreeNode<T>*root)
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
        if(pointer->letfchild)
            nodeQueue.push(pointer->letfchild);
        if(pointer->rightchild)
            nodeQueue.push(pointer->rightchild);
    }
}

void menu(BinaryTreeNode<T> *root);
{
    int number;
    cout<<"��ѡ��������Ĳ�����"<<endl<<"1.������ȱ���"<<endl<<"2.�ݹ���������"<<endl<<"3.�ǵݹ���������"<<endl;
    cin>>number;
    system(cls);
    switch(number)
    {
    case 1:
        leverOrder(BinaryTreeNode<T> *root); break;
    case 2:
        preOrder_recur(BinaryTreeNode<T> *root); break;
    case 3:
        preOrder_unrecur(BinaryTreeNode<T> root); break;
    default:
        cout<<"�Բ��������������������"<<endl;
    }

}
int main()
{
    BinaryTree<char> a();
    creat(a.root);
    menu(a.root);

}
