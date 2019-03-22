#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
struct node//�Խṹ�����ʽ�洢�߶���
{
    long long tree,left,right,lazy;
}a[800003];//�߶���ά����ֵ���߶���ˣ��߶��Ҷˣ�lazy���
long long n,m,l,k,r,x,y,find,srx,add,i,j;

void make(ll l,ll r,ll k);//�����߶���
void SUC(ll k);//������ǰ�ڵ��lazy���
void change(int k);//�������
void look(int k);//�����ѯ
int main()
{
    scanf("%lld%lld",&n,&m);//�����ʼ�߶γ��ȺͲ�������
    printf("finish input\n");
    make(1,n,1);//�����߶������߶δ�1��ʼ����n���������ڵ���1��
    for (i=1;i<=m;i++)//ִ��ÿһ������
    {
        scanf("%lld%lld%lld",&srx,&x,&y);
        find=0;
        if (srx==1)//SRX��1������������Ϣ
        {
            printf("srx=1\n",find);
            scanf("%lld",&add);
            change(1);//�������Ҫ��1��ʼ
        }
        if (srx==2)//SRX��2����ѯ������Ϣ
        {
            printf("srx=2\n",find);
            look(1);//�������һ���Ĵ�1��ʼ
            printf("%lld",find);
        }
    }
    return 0;
}

/*Ϊʲô������º�������Ҷ�Ҫ��1��ʼ��
    ����Ҫ����һ���߶����Ĵ洢��ʽ���߶���û���������һ���������棬����������һ��ʮ
����������ڽӱ��档�߶����Ĵ洢��ʽ�������ƣ���������ģ��洢�ġ�����tree[1]�Ǹ���
�ڵ㣬tree[2]��tree[1]�����ӣ�tree[3]��tree[1]���Һ��ӣ�tree[2]��������
tree[4],�Һ�����tree[5]��tree[3]��������tree[6],�Һ�����tree[7]������Ҫ�Ӹ���
�㿪ʼѰ�Ҿ�Ҫ��1��ʼ��
    ����һ��������Ǵ��߶���������Ĵ�С���⣬���ｨ�鿪n*4�Ĵ�С��n���߶��ܳ��ȣ�
����Ϊʲô�����߶����Ľṹ�й�ϵ���Լ��ټ������Ӿ��������ˡ��ϸ�֤����ٶȣ��ӣ�����*/

void make(ll l,ll r,ll k)//����һ���߶���
{
    ll mid;
    a[k].lazy=0;
    //�����ʱ���lazyֵ���Ϊ0������ֻ�мӼ�������ֻ��һ��lazy���
    a[k].left=l,a[k].right=r;//���߶���ÿһ���ڵ��ʾ�����������ٽ��Ǻ�
    if (l==r)
    {//������ٽ�������ٽ磬˵�����Խ��ж����ˣ��������ֻ��һ��ֵ
        scanf("%lld",&a[k].tree);
        return;
    }//��ô�������ֵ�������ֻ��һ�������������Ҫֵ
    mid=(l+r)/2;//����ѵ�ǰ�����۰�
    make(l,mid,k*2);//������������������
    make(mid+1,r,k*2+1);//������������������
    a[k].tree=a[k*2].tree+a[k*2+1].tree;
    //��Ϊ����ά����������ͣ�����ֱ�Ӱ����Ҷ��ӵ�ֵ���������Ǹ��׽ڵ��ֵ
    return;
}

void SUC(ll k)//����lazy��ǣ�k�ǵ�ǰ�ڵ���±�
{//ֻ��lazy���!=0��ʱ��Ż�ִ��
    ll l,r;
    l=k*2,r=k*2+1;//ȡ����ǰ�ڵ�����Ҷ���
    a[l].lazy+=a[k].lazy;//�ѵ�ǰ�ڵ��lazyֵ���ݸ����Ҷ���
    a[r].lazy+=a[k].lazy;
    //��Ϊ����ֻ�мӼ�������lazyֵ������+=�ķ�ʽ���ݸ����Ҷ���
    //���Ϊ���Ҷ��Ӹ����ˣ��������Ҷ��ӵĶ��ӻ�û����
    a[l].tree+=a[k].lazy*(a[l].right-a[l].left+1);
    a[r].tree+=a[k].lazy*(a[r].right-a[r].left+1);
    //�������Ҷ��ӵ�ֵ
    a[k].lazy=0;//���ѵ�ǰ�ڵ��lazyֵ��ʼ��
    return;
}

void change(int k)//�������
{//�����x��y����Ҫ��������������ٽ�
    ll mid;
    if (a[k].left>=x&&a[k].right<=y)
    {//�����ǰ�ڵ�����ʾ�����������ȫ��������Ҫ���µ������ھͰѵ�ǰ�������
        a[k].tree+=add*(a[k].right-a[k].left+1);
        a[k].lazy+=add;//����lazyֵ��Ǻ�
        return;
    }//ע��lazyֵ�ĸ���һ��Ҫ���ۼӵĲ�Ҫֱ�Ӹ�ֵ����Ȼ���׶�ʧ���ݵ���WA
    if (a[k].lazy>0) SUC(k);
    //����˽ڵ㲻�����������������lazy��ǣ��͸������Ķ��ӽڵ�
    mid=(a[k].left+a[k].right)/2;//�ѽڵ��ʾ����������
    if (x<=mid) change(k*2);//�������ܰ����������
    if (y>mid) change(k*2+1);//����ұ��ܰ��������ұ�
    a[k].tree=a[k*2].tree+a[k*2+1].tree;//���Ѷ��ӵ�ֵ���¸��˽ڵ�
    return;
}

void look(int k)//�������
{
    ll mid;
    if (a[k].left>=x&&a[k].right<=y)
    {//�����������ȫ�����������������ڣ���get�������ֵ
        find+=a[k].tree;
        return;
    }
    //���������ȡֵ���������ִ˽ڵ���lazy��ǣ��͸������Ķ��ӽڵ�
    if (a[k].lazy>0) SUC(k);
    mid=(a[k].left+a[k].right)/2;//���˽ڵ��ʾ����������
    if (x<=mid) look(k*2);//������Ҿ���
    if (y>mid) look(k*2+1);//�ұ����Ҿ���
    return;
}