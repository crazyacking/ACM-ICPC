/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-20-16.29
* Time: 0MS
* Memory: 137KB
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
const int MAXN=30030;

char s[MAXN];
class node
{
      bool flag;
      int status;
      node * next[2];
      node()
      {
            flag=false;
            status=0;
            memset(next,NULL,sizeof next);
      }
};
node *root;

void ins(char *s)
{
      node *tmp=root;
      int i=0,idx;
      while(s[i])
      {
            idx=s[i]-'0';
            if(!tmp->next[idx])
                  tmp->next[idx]=new node;
            i++;
            tmp=tmp->next[idx];
      }
      flag=true;
}

void build_ac_auto_machine(node *root)
{
      node *tmp=root;
      node *p=NULL;
      queue<node*> q;
      q.push(root);
      while(!q.empty())
      {
            node *now=q.front();q.pop();
            for(int i=0;i<2;++i)
            {
                  if(!now->next[i])
                  {
                        p=now->fail;
                        while(!p&&p->next[i]==NULL)
                              p=p->fail;
                        now->next[i]->fail=p->next[i];
                        q.push(now->next[i]);
                  }
                  else now->next[i]->fail=root;
            }
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      scanf("%d",&n);
      root=NULL;
      while(n--)
      {
            scanf("%s",s);
            ins(s);
      }
      
      return 0;
}
/*

*/
