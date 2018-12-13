#include <stdio.h>

int main(void)
{
int i,j,js=0,winb=0,winh=0,stack=0,ggdx,ggdy,flag;
int bj[225][10];
char a[15][15];
while(1){
js=0;winb=0;winh=0;stack=0;
    for (i=0;i<15;i++)
scanf("%s",&a[i]);
for (i=0;i<15;i++)
    {for(j=0;j<15;j++){
    //printf("%c",a[i][j]);
    if (a[i][j]==50)
        js++;
    else if(a[i][j]==48)
        js--;
    bj[i][j]=1;
    }
    //printf("\n");
    }
for (i=0;i<11;i++)    for(j=0;j<11;j++)
    {
        if(a[i][j]+a[i+1][j+1]+a[i+2][j+2]+a[i+3][j+3]+a[i+4][j+4]-240==10){
                bj[stack][0]=i;bj[stack][1]=j;
                bj[stack][2]=i+1;bj[stack][3]=j+1;
                bj[stack][4]=i+2;bj[stack][5]=j+2;
                bj[stack][6]=i+3;bj[stack][7]=j+3;
                bj[stack][8]=i+4;bj[stack][9]=j+4;
                stack++;
            winh=1;
        }else if(a[i][j]+a[i+1][j+1]+a[i+2][j+2]+a[i+3][j+3]+a[i+4][j+4]-240==0){
                bj[stack][0]=i;bj[stack][1]=j;
                bj[stack][2]=i+1;bj[stack][3]=j+1;
                bj[stack][4]=i+2;bj[stack][5]=j+2;
                bj[stack][6]=i+3;bj[stack][7]=j+3;
                bj[stack][8]=i+4;bj[stack][9]=j+4;
                stack++;
            winb=1;
        }
    }
for (i=4;i<15;i++)
    for(j=0;j<11;j++)
    {
        if(a[i][j]+a[i-1][j+1]+a[i-2][j+2]+a[i-3][j+3]+a[i-4][j+4]-240==10){
                bj[stack][0]=i;bj[stack][1]=j;
                bj[stack][2]=i-1;bj[stack][3]=j+1;
                bj[stack][4]=i-2;bj[stack][5]=j+2;
                bj[stack][6]=i-3;bj[stack][7]=j+3;
                bj[stack][8]=i-4;bj[stack][9]=j+4;
                stack++;
            winh=1;
        }else if(a[i][j]+a[i-1][j+1]+a[i-2][j+2]+a[i-3][j+3]+a[i-4][j+4]-240==0){
                bj[stack][0]=i;bj[stack][1]=j;
                bj[stack][2]=i-1;bj[stack][3]=j+1;
                bj[stack][4]=i-2;bj[stack][5]=j+2;
                bj[stack][6]=i-3;bj[stack][7]=j+3;
                bj[stack][8]=i-4;bj[stack][9]=j+4;
                stack++;
            winb=1;
        }
    }
for (i=0;i<15;i++)
    for(j=0;j<11;j++)
    {
        if(a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]+a[i][j+4]-240==10){
                bj[stack][0]=i;bj[stack][1]=j;
                bj[stack][2]=i;bj[stack][3]=j+1;
                bj[stack][4]=i;bj[stack][5]=j+2;
                bj[stack][6]=i;bj[stack][7]=j+3;
                bj[stack][8]=i;bj[stack][9]=j+4;
                stack++;
            winh=1;
        }else if(a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]+a[i][j+4]-240==0){
                bj[stack][0]=i;bj[stack][1]=j;
                bj[stack][2]=i;bj[stack][3]=j+1;
                bj[stack][4]=i;bj[stack][5]=j+2;
                bj[stack][6]=i;bj[stack][7]=j+3;
                bj[stack][8]=i;bj[stack][9]=j+4;
                stack++;
            winb=1;
        }
    }
for (i=0;i<11;i++)
    for(j=0;j<15;j++)
    {
        if(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]+a[i+4][j]-240==10){

                bj[stack][0]=i;bj[stack][1]=j;
                bj[stack][2]=i+1;bj[stack][3]=j;
                bj[stack][4]=i+2;bj[stack][5]=j;
                bj[stack][6]=i+3;bj[stack][7]=j;
                bj[stack][8]=i+4;bj[stack][9]=j;
                stack++;
            winh=1;
        }else if(a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]+a[i+4][j]-240==0){
                bj[stack][0]=i;bj[stack][1]=j;
                bj[stack][2]=i+1;bj[stack][3]=j;
                bj[stack][4]=i+2;bj[stack][5]=j;
                bj[stack][6]=i+3;bj[stack][7]=j;
                bj[stack][8]=i+4;bj[stack][9]=j;
                stack++;
            winb=1;
        }
    }
//for (i=0;i<15;i++)
  //  {for(j=0;j<15;j++)
   // printf("%d",bj[i][j]);
   // printf("\n");}
if (js<0 || js>1 || winh&&winb){
    printf("Impossible!\n");
}else{
    for(j=0;j<5;j++)
    {ggdx=bj[0][2*j];
    ggdy=bj[0][2*j+1];
    flag=1;
for(i=1;i<stack;i++)
if (!(ggdx==bj[i][0]&&ggdy==bj[i][1]||ggdx==bj[i][2]&&ggdy==bj[i][3]||ggdx==bj[i][4]&&ggdy==bj[i][5]||ggdx==bj[i][6]&&ggdy==bj[i][7]||ggdx==bj[i][8]&&ggdy==bj[i][9])){
   flag=0;
}
if (flag){
printf(winh?js==0?"Impossible!\n":"Black win!\n":winb?js==1?"Impossible!\n":"White win!\n":"Playing\n");
break;
}
}
if(!flag)
    printf("Impossible!\n");
}
}
}
