#include <stdio.h>
int main(){

    int i,j,k,m;
    int a[60][160];

    for(i=0;i<=59;i++) //控制行
    {
        for (j=0;j<=159;j++)//控制列
        {

        scanf("%d",&(a[i][j]));
        }
        printf("%d!!!!!!!!!!!!!!!!!!!!",i);
    }
        printf("\n\n\n\n\n");
    for(i=0;i<=59;i++) //控制行
    {
        for (j=0;j<=159;j++)//控制列
        {
            printf("%d",a[i][j]);
        }

    }
        printf("\n\n\n\n\n");
    for(i=0;i<=59;i++) //控制行
    {
        for (j=0;j<=159;j++)//控制列
        {
            if(a[i][j]==1)
                continue;
               for(k=0;k<=159;k++)//对疑似赛道进行循环判断
               {
                   if(a[i][j+k]==0)//如果还保持为疑似赛道
                   continue;//先继续循环
                   if(k<30)//结束后疑似赛道长度低于60个数组长度为干扰
                   {
                       j=j+k;//为外循环做好准备
                       break;//结束对疑似赛道的判断
                   }
                   else//find way长度为k
                   {
                    m=k/2;//算出赛道中点
                    a[i][j+m]=2;//将赛道中点画出
                    j=j+k;
                    break;//停止长度计算函数
                   }
               }
        }
    }
    for(i=0;i<=59;i++)
    {
        for(j=0;j<=159;j++)
        {
            printf("%d",a[i][j]);
        }
    printf("\n");
    }
    return 0;
}
