#include<stdio.h>
//#include<malloc.h>
#include<windows.h>
#include<stdlib.h>
typedef int DataType;

typedef struct Node
{
      int data;
      struct Node *next;
} QNode;
/*typedef struct{
      QNode *rear;
}LQueue;*/
struct Node *rear=NULL;


QNode *Init_LQueue(/*LQueue *q*/);
QNode *In_LQueue(struct Node *rear,int x);
void Empty_LQueue(struct Node *rear);
QNode *Out_LQueue(struct Node *rear);

int main()
{
      int i,x;
      while(1)
      {
            printf("\n\n\n                           输  入  你   的  选  择:");
            printf("\n\n\n                 【0】置空【1】判空【2】入队【3】出队【4】浏览元素\n\n");
            printf("输入你的选择：");
            scanf("%d",&i);
            switch(i)
            {
            case 0:
                  Init_LQueue(/*LQueue *q*/);
                  break;
            case 1:
                  Empty_LQueue(rear);
                  break;

            case 2:
                  printf("输入要入队的元素x");
                  scanf("%d",&x);
                  rear=In_LQueue(rear,x);
                  break;

            case 3:
                  rear=Out_LQueue(rear);
                  break;
            }
      }

}


QNode *Init_LQueue(/*LQueue *q*/)
{
      QNode *q=(QNode *)malloc(sizeof(QNode));
      q->data=0;
      rear=q;
      rear->next=rear;
      return rear;
}

void Empty_LQueue(struct Node *rear)
{
      if(rear->next==rear)
            printf("队列为空");
      else
            printf("队列不为空");
}

QNode *In_LQueue(QNode *rear,int x)
{
      QNode *p= (QNode *)malloc(sizeof(QNode));
      p->data=x;
//    p->next=NULL;
//    rear->next=p;
//    rear=p;


      p->next=rear->next;
      rear->next=p;
      rear=p;
      return rear;
}


QNode *Out_LQueue(struct Node *rear)
{
      QNode *p,*q;
      if(rear->next==rear)
      {
            printf("\n\n   队列目前没有元素");
            return rear;
      }
      else
      {
            {
                  q=rear->next;//头结点
                  p=q->next; //第一个节点
            }
            if(p==rear)
            {
                  printf("出队元素是：%d",p->data);
                  rear=q;
                  rear->next=rear;

                  if(rear->next==rear)
                  {
                        printf("p->data=%d",p->data);
                        printf("rear->data=%d",rear->data);
                  }
            }
            else
            {
                  printf("出队元素是：%d",p->data);
                  q->next=p->next;
            }
      }
      return rear;
}

//
//
//int main()
//{
//      int a;
//      Node *q;
//      DataType x;
//      while(1)
//      {
//            scanf("%d",&a);
//            switch(a)
//            {
//            case 1:
//                  Init_LQueue();
//                  break;
//            case 2:
//                  Empty_LQueue(q);
//                  break;
//            case 3:
//                  printf("输入要入队的元素x");
//                  scanf("%d",&x);
//                  In_LQueue(q,x);
//                  break;
//            case 4:
//                  Out_LQueue(rear);
//                  break;
//            }
//      }
//      return 0;
//}
//



