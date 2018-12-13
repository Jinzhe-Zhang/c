#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        if(n==0)
        {
            printf("Empty Array!");
            break;
        }
        else
        {
            int i,length=n;
            int *p = malloc(n*sizeof(int));
            for(i=0;i<n;i++)
            {
                scanf("%d",&p[i]);
            }
            int slow = 1,fast;
            for (fast = 1; fast < length; fast++)
            {
                if (p[fast] != p[slow - 1])
                {
                    p[slow++] = p[fast];
                }
            }
            length=slow;
            for(i=0;i<length;i++)
            {
                printf("%d",p[i]);
            }
            free(p);
            scanf("%d",&n);
        }
    }
    return 0;
}
