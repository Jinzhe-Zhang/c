#include<stdio.h>
static char num[10][3]={{"��"},{"һ"},{"��"},{"��"},{"��"},{"��"},{"��"},{"��"},{"��"},{"��"}};
static char digit[5][3]={"ʮ","��","ǧ","��","��"};
static char fu[3]="��";
int fals=0;
int wordstoint(char* word)
{   char* words=word;
    int jianceling=0;   //һǧ��һ������
    int jiance=0;   //һǧ��һ�����ٴμ��
    int dig=0;          //��ʮ��ǧλ
    int k=0;            //�ݴ���
    int m[4]={0};       //��ʮ��ǧλ����
    long int n=0;            //���յ���
    long int nn=0;             //�Ҳ������յ�����
    int jl=0;           //��¼֮ǰ������
    int a;
    int i,j;
    int sig=1;
    if(words[2]=='\n')
        printf("haha");
        if(strcmp(words,"��")==0)
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
                    //printf("��������");
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
                    a=-1;    //λ
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
                    //printf("��������");
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
                    //printf("��������");
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
                    //printf("��������");
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

                    //printf("��������");
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
                    //printf("��������");
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
                    a=-1;    //λ
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
                    //printf("��������");
                    fals=1;
                    return -1;
                }
            }
             else
                {
                    //printf("��������");
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
                   // printf("��������");
                    fals=1;
                    return -1;
}
}
if(jianceling == 1)
{
                    //printf("��������");
                    fals=1;
                    return -1;
}
else if(jl<14)
{
if(k!=0)
            {
                                if(m[0]!=0)
                {
                    //printf("��������");
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
                    a=-1;    //λ
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
                    //printf("��������");
                    fals=1;
                    return -1;
                }
            }
             else
                {
                    //printf("��������");
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
        printf("��");
        return;
    }
    if(nu<0)
    {
        printf("��") ;
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

           printf("%sǧ",num[n[i][3]]) ;
           begin=0;
        }
        if(n[i][2]!=0)
        {
            if(n[i][3]==0 && i<a-1)
               printf("��") ;
           printf("%s��",num[n[i][2]]) ;
           begin=0;
        }
        if(n[i][1]!=0)
        {
            if(n[i][2]==0 && (i<a-1 || n[i][3]!=0))
               printf("��") ;
               if(n[i][1]==1 && begin)
                printf("ʮ");
               else
           printf("%sʮ",num[n[i][1]]) ;
           begin=0;
        }
        if(n[i][0]!=0)
        {

            if(n[i][1]==0 && (i<a-1 || n[i][3]!=0 || n[i][2]!=0))
               printf("��") ;
           printf("%s",num[n[i][0]]) ;
           begin=0;
        }
        if(n[i][3]+n[i][2]+n[i][1]+n[i][0])
        {
        if(i%2==1)
           printf("��") ;int j;
        for(j=0;j<i/2;j++)
            printf("��");

        }
    }
}
int main()
{
    while(1){fals=0;
char string[100];//����һ����������������ַ���
scanf("%s",string);//�ڼ������������ģ�������س��ͺ�
int a=wordstoint(string);
if (fals)
{
    printf("��һ������������ͷ����\n\n");
    continue;
}
//printf("%d\n",a);
scanf("%s",string);//�ڼ������������ģ�������س��ͺ�
int signal=0;
if(strcmp(string,"����")==0)
    signal=1;
else if(strcmp(string,"��ȥ")==0)
    signal=2;
else if(strcmp(string,"����")==0)
    signal=3;
else if(strcmp(string,"����")==0)
    signal=4;
    else
    {
printf("����������������ͷ����\n\n");
    continue;
    }

scanf("%s",string);//�ڼ������������ģ�������س��ͺ�
int b=wordstoint(string);
if (b==-1)
{
    printf("�ڶ�������������ͷ����\n\n");
    continue;
}
//printf("%d\n\n",b);
//printf("�˻�Ϊ��%d\n",a*b);//��������������
//printf("��Ӧ����Ϊ��");
switch (signal){
case 1:
    printf("��Ϊ:");
printwordsfromint(a+b);
break;
case 2:
    printf("��Ϊ:");
printwordsfromint(a-b);
break;
case 3:
    printf("��Ϊ:");
printwordsfromint(a*b);
break;
case 4:
    if(b==0)
    {
        printf("��������Ϊ0");
        break;
    }
    printf("��Ϊ:");
printwordsfromint(a/b);
break;
}
    printf("\n\n");

    }
}
