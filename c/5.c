#include<stdio.h>
int main(){
int a,b=1,c=1,d=2;
scanf("%d",&a);
while(1){
if(a==1){
printf("%d",b);
break;
}
else if(a==2){
printf("%d",c);
break;
}
else{
a--;
b=c;
c=d;
d=b+c;
}
}
return 0;}
