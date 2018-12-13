#include <stdio.h>
#include <stdlib.h>
int main()
{
    char c;
    char* d=NULL;
    c=getchar();
    d=(char*)malloc(sizeof(char));
    printf("%c\n",*d);
    *d=c;
    printf("%c\n",*d);
    d=(char*)malloc(sizeof(char));
    printf("%c\n",*d);
}
