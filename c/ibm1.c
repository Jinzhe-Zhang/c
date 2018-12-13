#include <stdio.h>
#include <stdlib.h>
int main(){
    char c;
    char* a;
    char* d;
    int b=0;
d=a;
while((c=getchar())!='\n'){
        printf("%d",c);
    d=(char*)malloc(sizeof(char)*50);
    *d=c;
    d+=40;
}
printf("%c",d-40);
    d=(char*)malloc(sizeof(char)*50);
    d+=40;
    *d='\0';
printf("%c",d-40);
return 0;
}
