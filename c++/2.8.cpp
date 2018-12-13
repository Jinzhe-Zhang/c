#include <iostream>
using namespace std;
class LinkNode {
public:
    int data;
    LinkNode *next;
    LinkNode *prev;
    LinkNode(const int&value=0, LinkNode  *ptr1 = 0 ,LinkNode  *ptr2 = 0)
    {
        data=value;
        next=ptr2;
        prev=ptr1;
    }

    };
class LinkList
{
private:
    LinkNode *head, *tail;
    LinkNode *prevPtr, *currPtr;
    int length=1;
public:
    LinkList(int data){
    LinkNode *p=new LinkNode(data);
    head=tail=p;
    }
    void add(int data){
    LinkNode*p=new LinkNode(data,tail);
    tail->next=p;
    tail=p;
    length+=1;
    }
    void print (){
    currPtr=head;
        cout<<currPtr->data<<"  ";
    while(currPtr->next!=NULL){
        currPtr=currPtr->next;
        cout<<currPtr->data<<"  ";
    };
    cout<<"\n";
    }
        ~LinkList(){
        currPtr=prevPtr=head;
        for(int i=0;i<length-1;i++)
    {currPtr=prevPtr->next;
    delete prevPtr;
    prevPtr=currPtr;
    }
    delete currPtr;
    }
    LinkNode* find(int value)
    {
        currPtr=head;
        for(int i=0;i<length-1;i++)
        {
            if(currPtr->data==value)
            {
                return currPtr;
            }
            currPtr=currPtr->next;
        }
        if(currPtr->data==value)
        {
            return currPtr;
        }
        cout <<"unable to find"<<endl;
        return NULL;
    }
    void del(int value){
    if( (currPtr=find(value))!=NULL)
    {
        if(currPtr!=head && currPtr!=tail)
        {
                  currPtr->next->prev=currPtr->prev;
        currPtr->prev->next=currPtr->next;
        delete currPtr;
        length--;
        }
        else if (currPtr!=head && currPtr==tail)
        {
            currPtr->prev->next=NULL;
            tail=currPtr->prev;
            delete currPtr;
        length--;
        }        else if (currPtr==head && currPtr!=tail)
        {
            currPtr->next->prev=NULL;
            head=currPtr->next;
            delete currPtr;
        length--;
        }

    }
    }
};
int main(){
LinkList a(123);
a.add(159);
a.add(428);
a.add(523);
a.add(682);
a.add(159);
a.print();
a.del(159);
a.print();
a.del(159);
a.print();
a.del(159);
a.print();
}
