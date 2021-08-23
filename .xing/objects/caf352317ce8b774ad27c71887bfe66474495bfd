#include<stdio.h>
#include<stdlib.h>
long largest(long a[1000],long n)
{long big=*a;
for(int i=0;i<n;i++)
{if(big< *(a+i))big=*(a+i);}
return big;}
long access(long a[1000],long n,long i)
{if(i>=n || i<0)  return -1; 
return *(a+i);}
void pointer(long a[1000],long n)
{for(long i=0;i<n;i++)
printf("%p\n",a+i);}
int main()
{long n,acc,r,a[1000];printf("no of elements");
scanf("%ld",&n);
for(long i=0;i<n;i++)
scanf("%ld",&a[i]);
printf("largest element is %ld\n",largest(a,n));
printf("enter ith element to access");
scanf("%ld",&acc);
r=access(a,n,acc-1);
if(r!=-1)
printf("element at %ld th position %ld\n",acc,r);
else
printf("invalid position\n");
pointer(a,n);
return 0;
}