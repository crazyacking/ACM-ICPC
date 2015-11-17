/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Verdict: Accepted
*       Submission Date: 2015-11-17-21.26
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
const int MAXN=10010;

int a[MAXN],n;
struct Node
{
      int num;
      Node* left_son;
      Node* right_son;
};
Node *root;
void build_binary_tree()
{
      if(n<=0) return;
      Node now;
      root=&now;
      int cnt=0;
      now.num=a[cnt++];
      now.left_son=NULL;
      now.right_son=NULL;
      queue<Node*> Q;
      Q.push(&now);
      while(!Q.empty()) // BFS order build binary tree
      {
            Node* now=Q.front();
            cout<<"dizhi="<<now<<endl;
            Q.pop();
            if(cnt<n)
            {
                  now->left_son=new Node;
                  now->left_son->num=a[cnt++];
                  now->left_son->left_son=NULL;
                  now->left_son->right_son=NULL;
                  Q.push(now->left_son);
            }
            if(cnt<n)
            {
                  now->right_son=new Node;
                  now->right_son->num=a[cnt++];
                  now->right_son->left_son=NULL;
                  now->right_son->right_son=NULL;
                  Q.push(now->right_son);
            }
      }
}


void visit_binary_tree()
{
      Node now_node=(*root);
      cout<<"gege="<<now_node.num<<endl;
//      cout<<sizeof(*now_node.left_son)<<endl;
      cout<<now_node.left_son->num<<endl;
//      int d=(*now_node.left_son).num;
//      cout<<d<<endl;
      puts("-----------------------------------------------------------------");
//      cout<<(*now_node.left_son).num<<endl;
      puts("-----------------------------------------------------------------");
//      cout<<(now_node.left_son)->num<<endl;
//      puts("-----------------------------------------------------------------");
      Node now=(*root);
      queue<Node> Q;
      Q.push(now);
      while(!Q.empty())
      {
            now=Q.front();
            Q.pop();
            cout<<now.num<<endl;
            if(now.right_son!=NULL)
                  Q.push(*(now.right_son));
            if(now.left_son!=NULL)
                  Q.push(*(now.left_son));
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(cin>>n)
      {
            for(int i=0;i<n;++i)
                  cin>>a[i];
            build_binary_tree();
            puts("-----------------------------------------------------------------");

            visit_binary_tree();
      }
      return 0;
}
/*

*/
