#include<stdio.h>
static char num[10][3]={{"零"},{"一"},{"二"},{"三"},{"四"},{"五"},{"六"},{"七"},{"八"},{"九"}};
static char digit[5][3]={"十","百","千","万","亿"};
int wordstoint(char* word)
{   char* words=word;
    int jianceling=0;   //一千零一中零检测
    int dig=0;          //个十百千位
    int k=0;            //暂存数
    int m[4]={0};       //个十百千位的数
    long int n=0;            //最终的数
    long int nn=0;             //我才是最终的数！
    int jl=0;           //记录之前的数据
    int a;
    int i,j;
    if(words[2]=='\n')
        printf("haha");
while(*words != '/n')
{
    int hefa=0;
    for(i=1;i<10;i++)
    {
        if(words[1]==num[i][1] && words[0]==num[i][0])
        {hefa =1;
            if(k==0)
            {
                k=i;
                    jl=i;

                if(m[0]!=0)
                {
                    printf("输入有误1");
                    return -1;
                }
                else if(m[1]!=0)
                {
                    a=1;
                }
                else if(m[2]!=0)
                {
                    a=2;
                }
                else if(m[3]!=0)
                {
                    a=3;
                }
                else
                {
                    a=-1;    //位
                }
                if(a==-1 || a>dig+1 && jianceling==0 || a<dig+2 && jianceling==1)
                {
                    m[dig]=k;
                    k=i;
                    jl=i;
                    jianceling = 0;
                    dig=0;
                }
                else
                {
                    printf("输入有误2");
                    return -1;
                }
            }
        }
    }
    if(words[1]==num[0][1] && words[0]==num[0][0])
        {hefa=1;
            if(jianceling == 0 && jl>10)
            {
                jianceling == 1;
                    jl=10;
            }
            else
            {
                    printf("输入有误3");
                    return -1;
            }
        }
        for(i=0;i<3;i++)
        {if (words[1]==digit[i][1] && words[0]==digit[i][0])
        {hefa=1;
            if ( m[0] ==0 &&m[1] ==0&&m[2]==0&&m[3]==0)
                {
                    if(k==1 || k==0 && i!=1)
                    {
                    printf("输入有误4");
                    return -1;
                    }
                    else if(k==0)
                    {
                        k=1;
                        dig=1;
                        jianceling=0;
                        jl=i+11;
                    }
                    else
                    {
                        dig=i;
                        jianceling=0;
                        jl=i+11;
                    }
                }
                else
                {
                    if(k==0)
                    {

                    printf("输入有误5");
                    return -1;
                    }
                    else
                    {
                        dig=i;
                        jl=i+11;
                    }
                }
        }

        }
        for(i=3;i<5;i++)
        {hefa=1;
            if (words[1]==digit[i][1] && words[0]==digit[i][0])
                {
            if(jl>13 && i==4)
            {
                n*=100000000;
            }
            else if(jl != 10)
            {   if(k!=0)
            {
                                if(m[0]!=0)
                {
                    printf("输入有误6");
                    return -1;
                }
                else if(m[1]!=0)
                {
                    a=1;
                }
                else if(m[2]!=0)
                {
                    a=2;
                }
                else if(m[3]!=0)
                {
                    a=3;
                }
                else
                {
                    a=-1;    //位
                }
                if(a==-1 || a>dig+1 && jianceling==0 || a<dig+2 && jianceling==1)
                {
                    m[dig]=k;
                    jianceling = 0;
                    dig=0;
                nn+=n;
                n=m[3]*1000+m[2]*100+m[1]*10+m[0];
                n*= i==4 ? 100000000 : 10000;
                jl=i+11;
                m[0]=m[1]=m[2]=m[3]=0;
                }
                else
                {
                    printf("输入有误7");
                    return -1;
                }
            }
             else
                {
                    printf("输入有误8");
                    return -1;
                }
            }
        }}
if(hefa)
{
    words+=2;
}
else
{
                    printf("输入有误c");
                    return -1;
}
}
if(jianceling == 1)
{
                    printf("输入有误9");
                    return -1;
}
else if(jl<14)
{
if(k!=0)
            {
                                if(m[0]!=0)
                {
                    printf("输入有误0");
                    return -1;
                }
                else if(m[1]!=0)
                {
                    a=1;
                }
                else if(m[2]!=0)
                {
                    a=2;
                }
                else if(m[3]!=0)
                {
                    a=3;
                }
                else
                {
                    a=-1;    //位
                }
                if(a==-1 || a>dig+1 && jianceling==0 || a<dig+2 && jianceling==1)
                {
                    m[dig]=k;
                    jianceling = 0;
                    dig=0;
                nn+=n+m[3]*1000+m[2]*100+m[1]*10+m[0];
                m[0]=m[1]=m[2]=m[3]=0;
                }
                else
                {
                    printf("输入有误a");
                    return -1;
                }
            }
             else
                {
                    printf("输入有误b");
                    return -1;
                }
}
return nn;
}
int main()
{
char string[100];//定义一个数组存放你输入的字符串
scanf("%s",string);//在键盘上输入中文，输入完回车就好
wordstoint(string);
printf("%s",string);//输出你输入的中文
}
