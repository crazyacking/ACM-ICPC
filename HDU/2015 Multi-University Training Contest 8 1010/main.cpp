/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-13-15.11
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

char wen[111111][11111];
namespace ac_auto
{
char str[1000005];
struct node
{
      node *next[26];
      node *fail;
      int count;
      node()
      {
            for(int i = 0; i < 26; i++)
                  next[i] = NULL;
            count = 0;
            fail = NULL;
      }
}*q[1000005];
node *root;
int head, tail;

void Insert(char *str)
{
      node *p = root;
      int i = 0, index;
      while(str[i])
      {
            index = str[i] - 'a';
            if(p->next[index] == NULL)
                  p->next[index] = new node();
            p = p->next[index];
            i++;
      }
      p->count++;
}
void build_ac_automation(node *root)
{
      root->fail = NULL;
      q[tail++] = root;
      while(head < tail)
      {
            node *temp = q[head++];
            node *p = NULL;
            for(int i = 0; i < 26; i++)
            {
                  if(temp->next[i] != NULL)
                  {
                        if(temp == root) temp->next[i]->fail = root;
                        else
                        {
                              p = temp->fail;
                              while(p != NULL)
                              {
                                    if(p->next[i] != NULL)
                                    {
                                          temp->next[i]->fail = p->next[i];
                                          break;
                                    }
                                    p = p->fail;
                              }
                              if(p == NULL) temp->next[i]->fail = root;
                        }
                        q[tail++] = temp->next[i];
                  }
            }
      }
}
int Query(node *root,int idx)
{
      int i = 0, cnt = 0, index;
      node *p = root;
      while(wen[idx][i])
      {
            index = wen[idx][i] - 'a';
            while(p->next[index] == NULL && p != root) p = p->fail;
            p = p->next[index];
            if(p == NULL) p = root;
            node *temp = p;
            while(temp != root && temp->count != -1)
            {
                  cnt += temp->count;
                  temp = temp->fail;
            }
            i++;
      }
      return cnt;
}
}
using namespace ac_auto;


int main()
{
      int T, n,m;
      scanf("%d",&T);
      while(T--)
      {
            head = tail = 0;
            root = new node();
            scanf("%d %d",&n,&m);
            for(int i=0; i<n; ++i)
            {
                  scanf("%s",wen[i]);
            }
            for(int i=0; i<m; ++i)
            {
                  scanf("%s", str);
                  Insert(str);
            }
            build_ac_automation(root);
            for(int i=0; i<n; ++i)
            {
                  printf("%d\n", Query(root,i));
            }
      }
      return 0;
}
