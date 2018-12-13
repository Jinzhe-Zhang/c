#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
class Car
{
private:
    string carname;
    int movenum=0;
public:
    int gnum(){return movenum;}
    string gname(){return carname;}
    void snum(int num){movenum=num;}
    void sname(string name){carname=name;}
};
class Port
{
public:
    Car *aa;
    int length=0;
    int maxlength;
    Port(int i){
    maxlength=i;
    aa=new Car[i];
    length=0;
    }
    ~Port(){
    delete[] aa;}
    void print()
    {
        cout<<"port print\n";
        for(int i=0;i<length;i++)
        cout<<"carname  "<<aa[i].gname()<<"  movenum  "<<aa[i].gnum()<<"\n";
        cout<<"\n";
    }
    bool push(Car a){
        if(length<maxlength)
        {
    aa[length].sname(a.gname());
    aa[length].snum(a.gnum());
    length++;
            return true;
        }
        else
            return false;
    }
        bool push(string a){
                    if(length<maxlength)
        {
    aa[length].sname(a);
    aa[length].snum(0);
    length++;
            return true;
        }
        else
            return false;
    }
    int pop(char* a){
    int i=length-1;
    while(i>=0)
    {
        if(a == aa[i].gname())
        {
            int k=aa[i].gnum();
            for(int j=i;j<length-1;j++)
            {
                aa[j].sname(aa[j+1].gname());
                aa[j].snum(aa[j+1].gnum()+1);
            }
            length--;
            return k;
        }
        i--;
    }
    return -1;
    }
    int pop(Car aaa){
        string a=aaa.gname();
    int i=length-1;
    while(i>=0)
    {
        if(a == aa[i].gname())
        {
            for(int j=i;j<length-1;j++)
            {
                aa[j].sname(aa[j+1].gname());
                aa[j].snum(aa[j+1].gnum()+1);
            }
            length--;
            return true ;
        }
    }
    return false;
    }
};

int main(){
FILE *fp,*fw;
fp=fopen("data.txt","r");
fw=fopen("output.txt","w");
if(!fp){printf("FILE not found .\n"); return 0;}
Port port(5);
char c;
char s1[30];
int s1i=0;
char s2[10];
int a;
while(!feof(fp))
{
    cout<<"begin\n";
s1i=0;
while((c=fgetc(fp))!=' ')
{
    s1[s1i]=c;
    s1i++;
}
s1[s1i]='\0';
    fgets(s2,8,fp);
if(strcmp(s2,"departs")== 0 )
   {
   if((a=port.pop(s1))!=-1)
   {
       fprintf(fw , "%s was moved %d times while it was here\n" ,s1, a );
       printf( "%s was moved %d times while it was here\n" ,s1, a );
   }
   else
   {
       fprintf(fw , "Sorry ,%s is not found" , s1);
       printf("Sorry ,%s is not found" , s1);
   }
   }
   else if (strcmp(s2,"arrives") == 0)
   {
       if(!port.push(s1))
       {
       fprintf(fw , "Sorry %s, the lot is full\n" , s1);
       printf( "Sorry %s, the lot is full\n" , s1);
       }
   }
   else
   {
       fprintf(fw , "Unrecognize %s\n" , s2);
       printf("Unrecognize %s\n" , s2);
   }
   port.print();
if(!feof(fp))
fgetc(fp);
else
    break;
}
for(int i=port.length-1;i>=0;i--)
{
       fprintf(fw , "%s was moved %d times while it was here\n" ,port.aa[i].gname().c_str(), port.aa[i].gnum());
       printf( "%s was moved %d times while it was here\n" ,port.aa[i].gname().c_str(), port.aa[i].gnum() );
}
fclose(fp);
fclose(fw);
}
