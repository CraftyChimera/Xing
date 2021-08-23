#include<stdio.h>
void selection_sort(int a[100],int n)
{int min_in=0,k;
for(int i=0;i<n;i++)
{min_in=i;
for(int j=i+1;j<n;j++)
if(a[min_in]>a[j])min_in=j;
k=a[min_in];
a[min_in]=a[i];
a[i]=k;
printf("Pass%d\t",i+1);
for(int m=0;m<n;m++)
printf("%d\t",a[m]);
printf("\n");}
}


int main()
{int a[100];int n;
printf("Enter no of elements\n");
scanf("%d",&n);
printf("Enter array\n");
for(int i=0;i<n;i++)
{scanf("%d",&a[i]);}
selection_sort(a,n);
printf("Final Result\t");
for(int i=0;i<n;i++)
printf("%d\t",a[i]);
return 0;}