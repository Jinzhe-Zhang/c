#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
struct node//以结构体的形式存储线段树
{
    long long tree,left,right,lazy;
}a[800003];//线段树维护的值，线段左端，线段右端，lazy标记
long long n,m,l,k,r,x,y,find,srx,add,i,j;

void make(ll l,ll r,ll k);//构造线段树
void SUC(ll k);//处理当前节点的lazy标记
void change(int k);//区间更新
void look(int k);//区间查询
int main()
{
    scanf("%lld%lld",&n,&m);//输入初始线段长度和操作次数
    printf("finish input\n");
    make(1,n,1);//构造线段树（线段从1开始，到n结束，根节点是1）
    for (i=1;i<=m;i++)//执行每一步操作
    {
        scanf("%lld%lld%lld",&srx,&x,&y);
        find=0;
        if (srx==1)//SRX是1：更新区间信息
        {
            printf("srx=1\n",find);
            scanf("%lld",&add);
            change(1);//区间更新要从1开始
        }
        if (srx==2)//SRX是2：查询区间信息
        {
            printf("srx=2\n",find);
            look(1);//区间查找一样的从1开始
            printf("%lld",find);
        }
    }
    return 0;
}

/*为什么区间更新和区间查找都要从1开始？
    这里要解释一下线段树的存储方式：线段树没有像二叉树一样用链表存，更不会像我一样十
分奇葩地用邻接表存。线段树的存储方式跟堆类似，是用数组模拟存储的。即，tree[1]是父亲
节点，tree[2]是tree[1]的左孩子，tree[3]是tree[1]的右孩子；tree[2]的左孩子是
tree[4],右孩子是tree[5]；tree[3]的左孩子是tree[6],右孩子是tree[7]。所以要从根节
点开始寻找就要从1开始。
    还有一个问题就是存线段树的数组的大小问题，这里建议开n*4的大小（n是线段总长度）
至于为什么，跟线段树的结构有关系，自己举几个例子就能明白了。严格证明请百度（逃）……*/

void make(ll l,ll r,ll k)//构造一棵线段树
{
    ll mid;
    a[k].lazy=0;
    //构造的时候把lazy值标记为0，这里只有加减，所以只有一个lazy标记
    a[k].left=l,a[k].right=r;//把线段树每一个节点表示的区间左右临界标记好
    if (l==r)
    {//如果左临界等于右临界，说明可以进行读入了，这个区间只有一个值
        scanf("%lld",&a[k].tree);
        return;
    }//那么所读入的值就是这个只有一个数的区间的重要值
    mid=(l+r)/2;//否则把当前区间折半
    make(l,mid,k*2);//构建这段区间的左子树
    make(mid+1,r,k*2+1);//构建这段区间的右子树
    a[k].tree=a[k*2].tree+a[k*2+1].tree;
    //因为这里维护的是区间和，所以直接把左右儿子的值加起来就是父亲节点的值
    return;
}

void SUC(ll k)//处理lazy标记，k是当前节点的下标
{//只有lazy标记!=0的时候才会执行
    ll l,r;
    l=k*2,r=k*2+1;//取到当前节点的左右儿子
    a[l].lazy+=a[k].lazy;//把当前节点的lazy值传递给左右儿子
    a[r].lazy+=a[k].lazy;
    //因为更新只有加减，所以lazy值可以以+=的方式传递给左右儿子
    //标记为左右儿子更新了，但是左右儿子的儿子还没更新
    a[l].tree+=a[k].lazy*(a[l].right-a[l].left+1);
    a[r].tree+=a[k].lazy*(a[r].right-a[r].left+1);
    //更新左右儿子的值
    a[k].lazy=0;//并把当前节点的lazy值初始化
    return;
}

void change(int k)//区间更新
{//这里的x和y是需要更新区间的左右临界
    ll mid;
    if (a[k].left>=x&&a[k].right<=y)
    {//如果当前节点所表示的区间可以完全包含在需要更新的区间内就把当前区间更新
        a[k].tree+=add*(a[k].right-a[k].left+1);
        a[k].lazy+=add;//并把lazy值标记好
        return;
    }//注意lazy值的更新一定要是累加的不要直接赋值，不然容易丢失数据导致WA
    if (a[k].lazy>0) SUC(k);
    //如果此节点不满足更新条件并且有lazy标记，就更新它的儿子节点
    mid=(a[k].left+a[k].right)/2;//把节点表示的区间折中
    if (x<=mid) change(k*2);//如果左边能包含就找左边
    if (y>mid) change(k*2+1);//如果右边能包含就找右边
    a[k].tree=a[k*2].tree+a[k*2+1].tree;//最后把儿子的值更新给此节点
    return;
}

void look(int k)//区间查找
{
    ll mid;
    if (a[k].left>=x&&a[k].right<=y)
    {//如果此区间完全包含在所查找区间内，就get此区间的值
        find+=a[k].tree;
        return;
    }
    //如果不满足取值条件还发现此节点有lazy标记，就更新它的儿子节点
    if (a[k].lazy>0) SUC(k);
    mid=(a[k].left+a[k].right)/2;//将此节点表示的区间折中
    if (x<=mid) look(k*2);//左边能找就找
    if (y>mid) look(k*2+1);//右边能找就找
    return;
}
