#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct list
{
  int no;
  struct list *rptr;
  struct list *lptr;

};

void main()
{
     struct list *node,*first;
     int i,n;
     clrscr();
     first=node;
     printf("\n eneter number: ");
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
       printf("\n enter numebr: ");
       scanf("%d",&node->no);
       if(i==n)
       {
	 node->rptr=NULL;
       }
       else
       {
	 node->rptr=(struct list *)malloc(sizeof(struct list));
	 node->rptr->lptr=node;
	 node=node->rptr;
       }
     }
     node=first;
       for(i=1;i<=n;i++)
       {
	 printf("\n %d | %p | %p | %p |",node->no,node->lptr,node,node->rptr);
	 node=node->rptr;
       }
     getch();
}