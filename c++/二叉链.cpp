#include <iostream>
using namespace std;
template <typename T>
class binaryTreeNode {
public:
    T element;
    binaryTreeNode<T>* leftChild;
    binaryTreeNode<T>* rightChild;
    binaryTreeNode(){leftChild -> NULL;rightChild -> NULL;};
template <typename T>
binaryTreeNode<T>* AddNode(const T& key,int direction,binaryTreeNode<T>*& root)
{
    if(direction == 0)//����
    {
        if(root->leftChild == NULL){//�ҵ���Ӧ��Ҷ�ڵ����
            root->leftChild = new binaryTreeNode<T>(key);
        }
        else{
            root->leftChild = AddNode(key, direction, root->leftChild);
        }
    }

    else//�Һ���
    {
        if (root->rightChild == NULL) {//�ҵ���Ӧ��Ҷ�ڵ����
            root->rightChild = new binaryTreeNode<T>(key);
        }
        else{
            root->rightChild = AddNode(key, direction, root->rightChild);
        }
    }

    return root;
}

template <typename T>
void binaryTree<T>::AddNode(const T& key,int direction)
{
    AddNode(key, direction, mRoot);
}template <typename T>
binaryTreeNode<T>* binaryTree<T>::Create(){

    binaryTreeNode<T>* current = NULL;

    T val;

    cin >> val;//�����ֵ

    if(val == -1)//��ʶ��ǰ����Ϊ�գ�ת����һ�ڵ�
    {
        return NULL;
    }

    else{//�ݹ�Ĵ�����������
        current = new binaryTreeNode<T>;
        current->element = val;
        current->leftChild = Create();
        current->rightChild = Create();
        return current;
    }
}/*�����������ٲ������������ɾ��

1������ʹ�ø�������void distroy(binaryTreeNode<T>* pNode);�������ᴴ��һ���ֲ�����ʱ���������洫�ݵ�ָ��
��Ȼʵ��ָ��;ֲ�ָ�붼ִ��ͬһ��ѿռ䣬delete�ֲ�ָ��Ҳ��ɾ���������ṹ��ռ�õĶ��ڴ�
����ʵ��ָ�뽫��������ָ��״̬�����ֲ���Ԥ�ϵĴ���
��˴��ݵ���ָ������ã��������ܽ�ʵ��ָ���ÿա�

2��ʹ�õݹ鷽���ͷŽڵ�

*/

template <typename T>
void binaryTree<T>::distroy(binaryTreeNode<T>*& pNode)
{
    if(pNode)
    {
        distroy(pNode->leftChild);
        distroy(pNode->rightChild);
        delete pNode;
        pNode = NULL;
    }
}
template <typename T>
void binaryTree<T>::distroy()
{
    distroy(mRoot);
}template <typename T>
void binaryTree<T>::preOrder()
{
    cout <<"ǰ������� ";
    preOrder(mRoot);
    cout << endl;
}

/*
 ǰ�������
 1.�����ǵݹ�ʵ�֣�����Ҫ���ý�ֹ��������ǰ�ڵ�Ϊ��
 2.�ȷ��ʸ��ڵ㣬�ٷ�����ڵ㣬�������Һ���

 */
template <typename T>
void binaryTree<T>::preOrder(binaryTreeNode<T>* node)
{
    if(node == NULL)
        return;
    else{
        cout << node->element <<' ';
        preOrder(node->leftChild);
        preOrder(node->rightChild);
    }
}
};
