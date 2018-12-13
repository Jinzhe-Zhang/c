#include<stdio.h>
static char num[10][3]={{"零"},{"一"},{"二"},{"三"},{"四"},{"五"},{"六"},{"七"},{"八"},{"九"}};
static char digit[5][3]={"十","百","千","万","亿"};
static char fu[3]="负";
int fals=0;
int wordstoint(char* word)
{   char* words=word;
    int jianceling=0;   //一千零一中零检测
    int jiance=0;   //一千零一中零再次检测
    int dig=0;          //个十百千位
    int k=0;            //暂存数
    int m[4]={0};       //个十百千位的数
    long int n=0;            //最终的数
    long int nn=0;             //我才是最终的数！
    int jl=0;           //记录之前的数据
    int a;
    int i,j;
    int sig=1;
    if(words[2]=='\n')
        printf("haha");
        if(strcmp(words,"零")==0)
            return 0;
        if(words[1]==fu[1] && words[0]==fu[0])
        {
            sig=0;
            words+=2;
            word+=2;
        }
        if(words[1]==digit[0][1] && words[0]==digit[0][0])
        {
            k=1;
            jl=1;
        }
while(*words != '\0')
{
    int hefa=0;
    for(i=1;i<10;i++)
    {
        if(words[1]==num[i][1] && words[0]==num[i][0])
        {hefa =1;
            if(k!=0)
            {

                if(m[0]!=0)
                {
                    //printf("输入有误");
                    fals=1;
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
                if(a==-1&&(dig==3 &&jiance==0 || dig<3 && n+nn==0 &&jiance==0 || dig<3 && n+nn>0 && jiance>0 )  || a>dig+1 && jiance==1 || a<dig+2 && jiance==0)
                {
                    m[dig]=k;
                    k=i;
                    jl=i;
                    jiance = jianceling;
                    jianceling=0;
                    dig=0;
                   //printf("ha");
                }
                else
                {
                    //printf("输入有误");
                    fals=1;
                    return -1;
                }
            }
                else
                {
                   k=i;
                    jiance = jianceling;
                    jianceling=0;
                }
        }
    }
    if(words[1]==num[0][1] && words[0]==num[0][0])
        {hefa=1;
            if(jl>10)
            {
                jianceling = 1;
                    jl=10;
            }
            else
            {
                    //printf("输入有误");
                    fals=1;
                    return -1;
            }
        }
        for(i=0;i<3;i++)
        {if (words[1]==digit[i][1] && words[0]==digit[i][0])
        {hefa=1;
            if ( m[0] ==0 &&m[1] ==0&&m[2]==0&&m[3]==0)
                {
                    if(k==0)
                    {
                    //printf("输入有误");
                    fals=1;
                    return -1;
                    }
                    else
                    {
                        dig=i+1;
                        jianceling=0;
                        jl=i+11;
                    }
                }
                else
                {
                    if(k==0)
                    {

                    //printf("输入有误");
                    fals=1;
                    return -1;
                    }
                    else
                    {
                        dig=i+1;
                        jl=i+11;
                    }
                }
        }

        }
        for(i=3;i<5;i++)
        {
            if (words[1]==digit[i][1] && words[0]==digit[i][0])
                {hefa=1;
            if(jl>13 && i==4)
            {
                n*=100000000;
            }
            else if(jl != 10)
            {   if(k!=0)
            {
                                if(m[0]!=0)
                {
                    //printf("输入有误");
                    fals=1;
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
                if(a==-1&&(dig==3 &&jiance==0 || dig<3 && n+nn==0 &&jiance==0 || dig<3 && n+nn>0 && jiance>0 )  || a>dig+1 && jiance==1 || a<dig+2 && jiance==0)
                {
                    m[dig]=k;
                    jianceling = 0;
                    dig=0;
                nn+=n;
                n=m[3]*1000+m[2]*100+m[1]*10+m[0];
                n*= i==4 ? 100000000 : 10000;
                jl=i+11;
                m[0]=m[1]=m[2]=m[3]=k=0;
                }
                else
                {
                    //printf("输入有误");
                    fals=1;
                    return -1;
                }
            }
             else
                {
                    //printf("输入有误");
                    fals=1;
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
                   // printf("输入有误");
                    fals=1;
                    return -1;
}
}
if(jianceling == 1)
{
                    //printf("输入有误");
                    fals=1;
                    return -1;
}
else if(jl<14)
{
if(k!=0)
            {
                                if(m[0]!=0)
                {
                    //printf("输入有误");
                    fals=1;
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
                if(a==-1&&(dig==3 &&jiance==0 || dig<3 && n+nn==0 &&jiance==0 || dig<3 && n+nn>0 && jiance>0 )  || a>dig+1 && jiance==1 || a>=0 && a<dig+2 && jiance==0)
                {
                    m[dig]=k;
                    jianceling = 0;
                    dig=0;
                nn+=n;
                n=m[3]*1000+m[2]*100+m[1]*10+m[0];
                m[0]=m[1]=m[2]=k=m[3]=0;
                }
                else
                {
                    //printf("输入有误");
                    fals=1;
                    return -1;
                }
            }
             else
                {
                    //printf("输入有误");
                    fals=1;
                    return -1;
                }
}
return sig?nn+n:-nn-n;
}
void printwordsfromint(int nu)
{   int n[10][4]={0};
    int a=0;
    if(nu==0)
    {
        printf("零");
        return;
    }
    if(nu<0)
    {
        printf("负") ;
        nu=-nu;
    }
    int begin=1;
    while(nu>0)
    {
        n[a][0]=nu%10;
        n[a][1]=nu/10%10;
        n[a][2]=nu/100%10;
        n[a][3]=nu/1000%10;
        nu/=10000;
        a++;
    }
    int i;
    for(i=a-1;i>=0;i--)
    {
        if(n[i][3]!=0)
        {

           printf("%s千",num[n[i][3]]) ;
           begin=0;
        }
        if(n[i][2]!=0)
        {
            if(n[i][3]==0 && i<a-1)
               printf("零") ;
           printf("%s百",num[n[i][2]]) ;
           begin=0;
        }
        if(n[i][1]!=0)
        {
            if(n[i][2]==0 && (i<a-1 || n[i][3]!=0))
               printf("零") ;
               if(n[i][1]==1 && begin)
                printf("十");
               else
           printf("%s十",num[n[i][1]]) ;
           begin=0;
        }
        if(n[i][0]!=0)
        {

            if(n[i][1]==0 && (i<a-1 || n[i][3]!=0 || n[i][2]!=0))
               printf("零") ;
           printf("%s",num[n[i][0]]) ;
           begin=0;
        }
        if(n[i][3]+n[i][2]+n[i][1]+n[i][0])
        {
        if(i%2==1)
           printf("万") ;int j;
        for(j=0;j<i/2;j++)
            printf("亿");

        }
    }
}
int main()
{
    while(1){fals=0;
char string[100];//定义一个数组存放你输入的字符串
scanf("%s",string);//在键盘上输入中文，输入完回车就好
int a=wordstoint(string);
if (fals)
{
    printf("第一个数错误，请重头输入\n\n");
    continue;
}
//printf("%d\n",a);
scanf("%s",string);//在键盘上输入中文，输入完回车就好
int signal=0;
if(strcmp(string,"加上")==0)
    signal=1;
else if(strcmp(string,"减去")==0)
    signal=2;
else if(strcmp(string,"乘以")==0)
    signal=3;
else if(strcmp(string,"除以")==0)
    signal=4;
    else
    {
printf("符号输入有误，请重头输入\n\n");
    continue;
    }

scanf("%s",string);//在键盘上输入中文，输入完回车就好
int b=wordstoint(string);
if (b==-1)
{
    printf("第二个数错误，请重头输入\n\n");
    continue;
}
//printf("%d\n\n",b);
//printf("乘积为：%d\n",a*b);//输出你输入的中文
//printf("对应中文为：");
switch (signal){
case 1:
    printf("和为:");
printwordsfromint(a+b);
break;
case 2:
    printf("差为:");
printwordsfromint(a-b);
break;
case 3:
    printf("积为:");
printwordsfromint(a*b);
break;
case 4:
    if(b==0)
    {
        printf("除数不能为0");
        break;
    }
    printf("商为:");
printwordsfromint(a/b);
break;
}
    printf("\n\n");

    }
}
