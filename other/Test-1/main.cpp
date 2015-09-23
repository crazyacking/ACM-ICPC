#include<stdio.h>
#include<cstring>
#include<cstdlib>
typedef struct node
{
      int integer;
      struct node *next;
      node()
      {
            next=NULL;
      }
} INTLINK;

void lc(INTLINK *h)
{
      h=new INTLINK();
      h->next=NULL;
      h->integer=0;
}
void ll(INTLINK h,int e)
{
      INTLINK t;
      t.integer=e;
      t.next=NULL;
      h.next=&t;
      h=*h.next;
}
void ld(INTLINK h)
{
      puts("-----------------------------------------------------------------");
      while(h.next!=NULL)
      {
            printf("%d ",h.integer);
            h=*h.next;
      }
}

int main()
{
      INTLINK L;
      INTLINK head;
      head.next=&L;
      int x;
      scanf("%d",&x);
      while(x>=0)
      {
            ll(L,x);
            scanf("%d",&x);
      }
      ld(head);
}
