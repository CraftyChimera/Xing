#include<stdio.h>
#include<string.h>

int count(int* a)
{int i=0;
while(a[i]!=0)
i++;
return i;
}

int main()
{int a[23];
for(int i=0;i<20;i++)
a[i]=i+1;
a[20]=0;
printf("%d",count(&a[0]));
return 0;
}