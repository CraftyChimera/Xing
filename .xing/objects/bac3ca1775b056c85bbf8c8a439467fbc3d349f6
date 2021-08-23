#include<stdio.h>
long a[100];long top=-1;
void push(long b)
{top++;
if(top<100)
a[top]=b;
else
printf("no space");}

long pop()
{if(top!=-1)
{return a[top--];}
printf("No element in stack");
return -1;
}

void view()
{for(long i=0;i<=top;i++)
printf("%ld\t",a[i]);
}

int main()
{long a,chy;char ch='y';
while(ch=='y')
{printf("press 1 to push,2 to pop and 3 to view\n");
scanf("%ld",&chy);
if(chy==1)
{scanf("%ld",&a);
push(a);}
if(chy==2)
printf("%ld",pop());
if(chy==3)
view();
printf("press y to continue");
scanf(" %c",&ch);
}
return 0;
}