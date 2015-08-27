/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-27-19.11
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
char mat[10][10];
char wlist[400010][10];
int vis[500010];
int w,n,inq[10][10];
char rec[10];
int dir[][2]= {{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
int cnt,ch[410010][27],val[500010],ids[500010];
int point[]= {0,0,0,1,1,2,3,5,11,11,11};
int ans_num,ans_point;
char anschar[10];
void inserts(char* s,int num)
{
      int rt=0;
      int len=strlen(s);
      for(int i=0; i<len; i++)
      {
            int k=s[i]-'A';
            if(ch[rt][k]==-1)
            {
                  ch[rt][k]=cnt++;
            }
            rt=ch[rt][k];
      }
      val[rt]=point[len];
      ids[rt]=num;
}
void solve(char* s)
{
      int rt=0;
      int len=strlen(s);
      for(int i=0; i<len; i++)
      {
            int k=s[i]-'A';
            if(ch[rt][k]==-1) break;
            rt=ch[rt][k];
      }
      if(val[rt]!=-1 && vis[ids[rt]]==0)
      {
            vis[ids[rt]]=1;
            ans_num++;
            ans_point+=val[rt];
            if(ans_num==1)
                  memcpy(anschar,s,10);
            else if(len==strlen(anschar) && strcmp(s,anschar)<0)
                  memcpy(anschar,s,10);
            else if(len>strlen(anschar))
                  memcpy(anschar,s,10);
      }
}
void dfs(int x,int y,int d)
{
      if(d>8) return;
      rec[d-1]=mat[x][y];
      rec[d]='\0';
      solve(rec);
      inq[x][y]=1;
      for(int i=0; i<8; i++)
      {
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(nx<0 || ny<0 || nx>=4 || ny>=4) continue;
            if(inq[nx][ny]) continue;
            inq[nx][ny]=1;
            dfs(nx,ny,d+1);
            inq[nx][ny]=0;
      }
      inq[x][y]=0;
}
int main()
{
      while(scanf("%d",&w)!=EOF)
      {
            memset(ch,-1,sizeof ch);
            memset(val,-1,sizeof val);
            memset(ids,-1,sizeof ids);
            cnt=1;
            for(int i=0; i<w; i++)
            {
                  scanf("%s",wlist[i]);
                  inserts(wlist[i],i);
            }
            scanf("%d",&n);
            for(int i=0; i<n; i++)
            {
                  memset(vis,0,sizeof vis);
                  ans_num=ans_point=0;
                  for(int j=0; j<4; j++) {scanf("%s",mat[j]);}
                  for(int q=0; q<4; q++)
                        for(int k=0; k<4; k++)
                        {
                              dfs(q,k,1);
                        }
                  printf("%d %s %d\n",ans_point,anschar,ans_num);
            }
      }
      return 0;
}
