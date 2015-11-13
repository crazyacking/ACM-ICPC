/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Verdict: Accepted
*       Submission Date: 2015-11-12-13.05
*/
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


/* 算法设计题：以二叉链表作为二叉树的存储结构，编写以下算法：
（1）统计二叉树的叶结点个数。
（2）交换二叉树每个结点的左孩子和右孩子。
（3）设计二叉树的双序遍历算法（双序遍历是指对于二叉树的每一个结点来说，先访问这个结点，再按双序遍历它的左子树，然后再一次访问这个结点，接下来按双序遍历它的右子树）。
（4）计算二叉树最大的宽度（二叉树的最大宽度是指二叉树所有层中结点个数的最大值）。
*/

struct Node
{
      int data;
      Node* left_son;
      Node* right_son;
      int layer;
      Node() {}
      Node(int x,Node* lson,Node* rson,int layer):data(x),left_son(lson),right_son(rson),layer(layer) {}
};

template<class T>
class Binary_Tree
{
public:
      Binary_Tree() {}
      ~Binary_Tree() {}
      int Counter_Node_Number();
      bool Change_Node_LRson(int x);
      void Double_Order_Visit();
      int Calc_Max_Width();
protected:
private:
};
Node* root;


template<class T>
int Binary_Tree<T>::Counter_Node_Number()
{
      int cnt=0;
      queue<T> Q;
      if((*root).left_son)
      {
            Q.push(*((*root).left_son));
            cnt++;
      }
      if((*root).right_son)
      {
            Q.push(*((*root).right_son));
            cnt++;
      }
      while(!Q.empty())
      {
            T Now_Node=Q.front();
            Q.pop();
            if(Now_Node->left_son)
            {
                  Q.push(*(Now_Node->left_son));
                  cnt++;
            }
            if(Now_Node.right_son)
            {
                  Q.push(*(Now_Node->right_son));
                  cnt++;
            }
      }
      return cnt;
}

template<class T>
bool Binary_Tree<T>::Change_Node_LRson(int x)
{
      int index=0;
      int cnt=Binary_Tree<T>::Counter_Node_Number();
      Node Change_Node;
      if(cnt<x)
            return false;
      else
      {
            queue<T> Q;
            if((*root).left_son)
            {
                  Q.push(*((*root).left_son));
                  cnt++;
            }
            if(x==cnt) Change_Node=Q.front();
            if((*root).right_son)
            {
                  Q.push(*((*root).right_son));
                  cnt++;
            }
            if(x==cnt) Change_Node=Q.front();
            while(!Q.empty())
            {
                  T Now_Node=Q.front();
                  Q.pop();
                  if(Now_Node->left_son)
                  {
                        Q.push(*(Now_Node->left_son));
                        cnt++;
                  }
                  if(x==cnt)
                  {
                        Change_Node=Q.front();
                        break;
                  }
                  if(Now_Node.right_son)
                  {
                        Q.push(*(Now_Node->right_son));
                        cnt++;
                  }
                  if(x==cnt)
                  {
                        Change_Node=Q.front();
                        break;
                  }
            }
            // clear Queue
            while(!Q.empty())
                  Q.pop();
      }
      // change right son and left son
      Node* tmp=Change_Node.right_son;
      Change_Node.right_son=Change_Node.left_son;
      Change_Node.left_son=tmp;
      return true;
}

template<class T>
void Binary_Tree<T>::Double_Order_Visit()
{
      // use stack on STL
      stack<T> stk;
      // Notice: Don't reverse it!
      if((*root).right_son)
      {
            stk.push(*((*root).right_son));
            // print result
      }
      if((*root).left_son)
      {
            stk.push(*((*root).left_son));
            // print result
      }
      Node Now_Node;
      while(!stk.empty())
      {
            Now_Node=stk.top();
            if(Now_Node.right_son)
            {
                  stk.push(*Now_Node.right_son);
                  // print result
            }
            if(Now_Node.left_son)
            {
                  stk.push(*Now_Node.left_son);
                  // print result
            }
      }
}

template<class T>
int Binary_Tree<T>::Calc_Max_Width()
{
      queue<T> Q;
      if((*root).left_son)
      {
            (*(*root).left_son).layer=2;
            Q.push(*(*root).left_son);

      }
      if((*root).right_son)
      {
            (*(*root).right_son).layer=2;
            Q.push(*(*root).right_son);
      }
      int Max_Width=0;
      int tmp_cnt=0;
      int Now_Layer=2;
      while(!Q.empty())
      {
            Node Now_Node=Q.front();
            Q.pop();
            if(Now_Layer==Now_Node.layer)
            {
                  ++tmp_cnt;
            }
            else
            {
                  Max_Width=max(Max_Width,tmp_cnt);
                  tmp_cnt=0;
                  Now_Layer=Now_Node.layer;
            }
            if(Now_Node.left_son)
            {
                  Now_Node=Now_Node.left_son;
                  Now_Node.layer=Now_Layer+1;
                  Q.push(Now_Node);
            }
            if(Now_Node.right_son)
            {
                  Now_Node=Now_Node.right_son;
                  Now_Node.layer=Now_Layer+1;
                  Q.push(Now_Node);
            }
      }
      return Max_Width;
}


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      return 0;
}
/*

*/
