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
cout << "栈已满" << endl;
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
cout << "队列为空";
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
cout << "队列为空";
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
cout  << num << "号";
switch (j)
{
case 0:
cout<<"普通";
break;
case 1:
cout<<"VIP";
break;
case 2:
cout<<"对公";
}


cout<<"顾客进入" << endl;
}
}
if (flag == 0)
{
for (int i = 0; i<3; i++)
{
if (!a[0].IsEmpty())
{
a[0].DeQueue(x);
cout << "请" << x << "号用户到" << i + 1 << "号普通窗口办理业务" << endl;
}
}
if (!a[1].IsEmpty())
{
a[1].DeQueue(x);
cout << "请" << x << "号用户到4号VIP窗口办理业务" << endl;
}
else if (!a[0].IsEmpty())
{
a[0].DeQueue(x);
cout << "请" << x << "号用户到4号VIP窗口办理业务" << endl;
}
if (!a[2].IsEmpty())
{
a[2].DeQueue(x);
cout << "请" << x << "号用户到5号公共窗口办理业务" << endl;
}
else if (!a[0].IsEmpty())
{
a[0].DeQueue(x);
cout << "请" << x <<"号用户到5号公共窗口办理业务" << endl;
}
flag = 1;
}
else
{
flag = 0;
}
}
cout << "12秒模拟结束后，还有" << num - x << "位用户在等待队列中" << endl;
system("pause");
return 0;
}
