#include<stdio.h>
#include<stdlib.h>
struct link
{int a;struct link* next;
};
struct link *head=NULL,*now=NULL,*b=NULL;

void createnewnode(int a)
{if(head==NULL)
 { head=(struct link*)malloc(sizeof(struct link));
     head->a=a;
  head->next=NULL;
  now=head;
  return;}
struct link* ptr=(struct link*)malloc(sizeof(struct link));
now->next=ptr;
now=ptr;
now->a=a;
now->next=NULL;
if(b==NULL)b=head->next;
return;}

void traversenode()
{for(struct link* p=head;p!=NULL;p=p->next)
 printf("\t%d\t",p->a);
}

int main()
{int n,m;scanf("%d",&n);
while(n--)
{scanf("%d",&m);
createnewnode(m);}
traversenode();
return 0;
}