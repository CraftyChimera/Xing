#include<stdio.h>
void bubble_sort(int a[100],int n)
{int pass=0,k;
for(pass;pass<n-1;pass++)
{for(int j=0;j<n-1;j++)
if(a[j]>a[j+1])
{k=a[j+1];
a[j+1]=a[j];
a[j]=k;}
printf("pass%d\t",pass+1);
for(int i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
}}

int main()
{int a[100];int n;
printf("Enter no of elements\n");
scanf("%d",&n);
printf("Enter array\n");
for(int i=0;i<n;i++)
{scanf("%d",&a[i]);}
bubble_sort(a,n);
printf("Final Result\t");
for(int i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;}