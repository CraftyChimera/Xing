#include<stdio.h>
#include<stdlib.h>
long largest2(long a[1000][1000],long m,long n)
{long big=**a;long big2=big;
for(int i=0;i<m;i++)for(int j=0;j<n;j++)
{if(big< *(*(a+i)+j))
{big2=big; big=*(*(a+i)+j);
}else if(big2 < *(*(a+i)+j))
{big2=*(*(a+i)+j);
}}return big2;}
long access(long a[1000][1000],long m,long n,long i,long j)
{if(i>=n || j>=m || i<0 || j<0)  return -1; 
return *(*(a+i)+j);}
void pointer(long a[1000][1000],long m,long n)
{for(long i=0;i<m;i++){for(long j=0;j<n;j++)printf("%p\t",*(a+i)+j);printf("\n");}}
int main()
{long m,n,p,q,r,a[1000][1000];printf("no of rows");
scanf("%ld",&m);
printf("no of columns");
scanf("%ld",&n);
for(long i=0;i<m;i++) for(long j=0;j<n;j++)
scanf("%ld",&a[i][j]);
if(n!=1) printf("2nd largest element is %ld\n",largest2(a,m,n));
else printf("no 2nd largest element in a array of only one element");
printf("enter ith row to access");scanf("%ld",&p);printf("enter jth column to access");
scanf("%ld",&q);r=access(a,m,n,p-1,q-1);
if(r!=-1)printf("element at %ld th row %ld column is %ld\n",p,q,r);
else printf("invalid position\n");
pointer(a,m,n);
return 0;
}