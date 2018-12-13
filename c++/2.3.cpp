#include <iostream>
using namespace std;
class LinkNode {
public:
    int data;
    LinkNode *link;
    LinkNode(const int&value, LinkNode  *ptr = 0)
    {
        data=value;
        link=ptr;
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
    LinkNode*p=new LinkNode(data);
    tail->link=p;
    tail=p;
    length+=1;
    }
    void print (){
    currPtr=head;
        cout<<currPtr->data<<"  ";
    while(currPtr->link!=NULL){
        currPtr=currPtr->link;
        cout<<currPtr->data<<"  ";
    };
    cout<<"\n";
    }
    void invert(){LinkNode* nextPtr=head;
        currPtr=prevPtr=head;
        if(length==2)
        {
             tail->link=head;
             head->link=NULL;
        head=tail;
        tail=currPtr;
        }
       else if(length >2)
       {currPtr=prevPtr->link;
       nextPtr=currPtr->link;
       head->link=NULL;
            for(int i=0;i<length-3;i++)
        {
            currPtr->link=prevPtr;
            prevPtr=currPtr;
            currPtr=nextPtr;
            nextPtr=nextPtr->link;
        }
        nextPtr->link=currPtr;
        currPtr->link=prevPtr;
        tail=head;
        head=nextPtr;
       }

    };
    ~LinkList(){
        currPtr=prevPtr=head;
        for(int i=0;i<length-1;i++)
    {currPtr=prevPtr->link;
    delete prevPtr;
    prevPtr=currPtr;
    }
    delete currPtr;
    }
};
int main(){
int i;
cout<<"initialize:"<<endl;
cin>>i;
LinkList a(i);
for(int j=0;j<10;j++)
{

cout<<"add:"<<endl;
cin>>i;
a.add(i);
}
a.print();
a.invert();
cout<<"After invert:\n";
a.print();

}
