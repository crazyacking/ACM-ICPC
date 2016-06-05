#include <queue>
#include <cstdio>

template<class T>
struct LinkNode //队列结点的定义
{
      T data;
      LinkNode *link;
      LinkNode<T>(T x):data(0),link(NULL) {}

};
template<class T>
class LinkedQueue // 函数、变量的定义和声明
{
public:
      LinkedQueue():rear(NULL),top(NULL) {}
      ~LinkedQueue() {makeEmpty();}
      bool EnQueue(const T& x);
      bool DeQueue(T& x);
      bool getFront(T& x)const;
      void makeEmpty();
      bool IsEmpty()const {return(top==rear)?true:false;}
      int getSize()const;
protected:
      LinkNode<T> *top, *rear;
};

template<class T>
void LinkedQueue<T>::makeEmpty()  //置空队列
{
      LinkNode<T> *p;
      while(top!=NULL)
      {
            p=top;
            top=top->link;
            delete p;
      }
};

template<class T>
bool LinkedQueue<T>::EnQueue(const T& x) //进队
{
      if(top==NULL)
      {
            top=rear=new LinkNode<T>(x);//空队列时，新结点成为队列的第一个结点，既是对头也是队尾
            if(top==NULL) return false;
      }
      else
      {
            rear->link=new LinkNode<T>(x);//非空时在链尾追加新的结点并更新队尾指针
            if(rear->link==NULL) return false;
            rear=rear->link;
      }
      return true;
};

template<class T>
bool LinkedQueue<T>::DeQueue(T& x)  // 出队
{
      if(IsEmpty()==true) return false;
      LinkNode<T> *p=top;
      x=top->data;
      top=top->link;
      delete p;
      return true;
};

template<class T>
bool LinkedQueue<T>::getFront(T& x)const // 取队首元素
{
      if(IsEmpty()==true) return false;
      x=top->data;
      return true;
};

template<class T>
int LinkedQueue<T>::getSize()const // 返回大小
{
      LinkNode<T> *p=top;
      int k=0;
      while(p!=NULL)
      {
            p=p->link;
            k++;
      }
      return k;
};

int main()
{
      return 0;
}
/*

*/
