#include <stdio.h>
int main(){

    int i,j,k,m;
    int a[60][160];

    for(i=0;i<=59;i++) //������
    {
        for (j=0;j<=159;j++)//������
        {

        scanf("%d",&(a[i][j]));
        }
        printf("%d!!!!!!!!!!!!!!!!!!!!",i);
    }
        printf("\n\n\n\n\n");
    for(i=0;i<=59;i++) //������
    {
        for (j=0;j<=159;j++)//������
        {
            printf("%d",a[i][j]);
        }

    }
        printf("\n\n\n\n\n");
    for(i=0;i<=59;i++) //������
    {
        for (j=0;j<=159;j++)//������
        {
            if(a[i][j]==1)
                continue;
               for(k=0;k<=159;k++)//��������������ѭ���ж�
               {
                   if(a[i][j+k]==0)//���������Ϊ��������
                   continue;//�ȼ���ѭ��
                   if(k<30)//�����������������ȵ���60�����鳤��Ϊ����
                   {
                       j=j+k;//Ϊ��ѭ������׼��
                       break;//�����������������ж�
                   }
                   else//find way����Ϊk
                   {
                    m=k/2;//��������е�
                    a[i][j+m]=2;//�������е㻭��
                    j=j+k;
                    break;//ֹͣ���ȼ��㺯��
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
