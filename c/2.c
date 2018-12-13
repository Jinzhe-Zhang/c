#include <stdio.h>
int main(){
float k=0.1;
if(k*10==1)
    printf("k*10==1\n");
else
    printf("k*10!=1\n");
    printf("%.16f",k);
k*=10;
if(k==1)
    printf("乘以10后k==1\n");
else
    printf("乘以10后k!=1\n");
    printf("%.16f",k);
    k=1.000000001324;
    printf("%.16f",1.000000001324);
    printf("%.16f",k);
if(k==1)
    printf("乘以10后k==1\n");
else
    printf("乘以10后k!=1\n");
    printf("%.16f",k);
}
