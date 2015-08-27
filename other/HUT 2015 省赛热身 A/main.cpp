/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-27-13.27
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

int score,num;
bool v[5000010],vv[10][10];
int dx[]= {1,1,0,-1,-1,-1,0,1};
int dy[]= {0,1,1,1,0,-1,-1,-1};
int val[]={0,0,0,1,1,2,3,5,11,11,11};
char str[300010][10],Mat[4][5],ans[10],tmp[10];

struct node
{
      node *Next[26];
      int sc,num;
      bool flag;
      node()
      {
            for(int i=0; i<26; ++i) Next[i]=NULL;
            num=0,sc=-1;
      }
} *root;


void Insert(char *s,int id)
{
      node *p=root;
      int i=0,idx;
      while(s[i])
      {
            idx=s[i]-'A';
            if(p->Next[idx]==NULL)
                  p->Next[idx]=new node();
            p=p->Next[idx];
            ++i;
      }
      p->num=id;
      p->sc=val[strlen(s)];
}

void Matching(char *s)
{
      int i=0,idx;
      node *p=root;
      int len=strlen(s);
      while(s[i])
      {
            idx=s[i]-'A';
            if(p->Next[idx]==NULL) break;
            p=p->Next[idx];
            ++i;
      }
      if(v[p->num]==false && p->sc!=-1)
      {
            ++num;
            score+=p->sc;
            v[p->num]=true;
            if(num==1 || (strlen(s)>strlen(ans)) || ((strlen(s)==strlen(ans) && strcmp(s,ans)<0)) )
                  memcpy(ans,s,10);
      }
}

void dfs(int x,int y,int cnt)
{
      if(cnt>8) return;
      tmp[cnt-1]=Mat[x][y];
      tmp[cnt]='\0';
      Matching(tmp);
      vv[x][y]=true;
      for(int i=0;i<8;++i)
      {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(vv[xx][yy]!=true && (xx>=0&&xx<4&&yy>=0&&yy<4))
            {
                  vv[x][y]=1;
                  dfs(xx,yy,cnt+1);
                  vv[x][y]=0;
            }
      }
      vv[x][y]=0;
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,m;
      scanf("%d",&n);
      root=new node();
      for(int i=0; i<n; ++i)
      {
            scanf("%s",str[i]);
            Insert(str[i],i);
      }
      scanf("%d",&m);
      while(m--)
      {
            memset(v,0,sizeof v);
            score=num=0;
            for(int i=0; i<4; ++i)
                  scanf("%s",Mat[i]);
            for(int i=0; i<4; ++i)
                  for(int j=0; j<4; ++j)
                        dfs(i,j,1);
            printf("%d %s %d\n",score,ans,num);
      }
      return 0;
}
/*

*/
