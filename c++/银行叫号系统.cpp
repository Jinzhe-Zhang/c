#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
template<class T>
class Queue
{
private:
int maxSize;
int front;
int real;
int *queue;
public:
Queue(int size)
{
maxSize = size + 1;
queue = new T[maxSize];
front = real = 0;
}
Queue()
{
maxSize = 10;
queue = new T[maxSize];
front = real = 0;
}
~Queue()
{
delete[]queue;
}
void Clear()
{
front = real;
}
bool Enqueue(T &item)
{
if ((real + 1) % maxSize == front)
{
cout << "ջ����" << endl;
return false;
}
queue[real] = item;
real = (real + 1) % maxSize;
return true;
}
bool DeQueue(T &item)
{
if (real == front)
{
cout << "����Ϊ��";
return false;
}
else
{
item = queue[front];
front = (front + 1) % maxSize;
return true;
}
}
int GetQueue()
{
if (real == front)
{
cout << "����Ϊ��";
return false;
}
else
{
return queue[front];
}
}
bool IsEmpty()
{
if (front == real)
{
return true;
}
else
{
return false;
}
}
};
int main()
{
srand(time(0));
Queue<int> a[3];
int num = 0;
int flag = 0;
int count = 0;
int x;
for (int i = 0; i <= 12; i += 2)
{
for (int j = 0; j<3; j++)
{
if (j == 0)
count = rand() % 4 + 1;
else
count = rand() % 2;
for (int k = 0; k<count; k++)
{
a[j].Enqueue(++num);
cout  << num << "��";
switch (j)
{
case 0:
cout<<"��ͨ";
break;
case 1:
cout<<"VIP";
break;
case 2:
cout<<"�Թ�";
}


cout<<"�˿ͽ���" << endl;
}
}
if (flag == 0)
{
for (int i = 0; i<3; i++)
{
if (!a[0].IsEmpty())
{
a[0].DeQueue(x);
cout << "��" << x << "���û���" << i + 1 << "����ͨ���ڰ���ҵ��" << endl;
}
}
if (!a[1].IsEmpty())
{
a[1].DeQueue(x);
cout << "��" << x << "���û���4��VIP���ڰ���ҵ��" << endl;
}
else if (!a[0].IsEmpty())
{
a[0].DeQueue(x);
cout << "��" << x << "���û���4��VIP���ڰ���ҵ��" << endl;
}
if (!a[2].IsEmpty())
{
a[2].DeQueue(x);
cout << "��" << x << "���û���5�Ź������ڰ���ҵ��" << endl;
}
else if (!a[0].IsEmpty())
{
a[0].DeQueue(x);
cout << "��" << x <<"���û���5�Ź������ڰ���ҵ��" << endl;
}
flag = 1;
}
else
{
flag = 0;
}
}
cout << "12��ģ������󣬻���" << num - x << "λ�û��ڵȴ�������" << endl;
system("pause");
return 0;
}
