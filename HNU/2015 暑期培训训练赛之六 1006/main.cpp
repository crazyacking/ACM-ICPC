/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-09-15.51
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

const int MAXN=50010;
struct L
{
      int sx,sy,ex,ey,id;
      L(int x1,int y1,int x2,int y2,int i) : sx(x1),sy(y1),ex(x2),ey(y2),id(i){}
};
int n;
vector<L> L1,L2;


LL A[MAXN];
void scan(int &x)
{
      x=0;
      char c=getchar();
      while(!(c>='0' && c<='9'  || c=='-')) { c=getchar(); }
      bool flag=1;
      if(c=='-')
      {
            flag=0; c=getchar();
      }
      while(c>='0' && c<='9')
      {
            x=x*10+c-'0'; c=getchar();
      }
      if(!flag) { x=-x; }
}
void scan2(int &x,int &y) { scan(x),scan(y);}
void scan3(int &x,int &y,int &z) { scan(x),scan(y),scan(z); }
/**************************************END     define***************************************/

bool cmp1(L a,L b)  //
{
      return a.sx==b.sx?a.sy<b.sy:a.sx<b.sx;
}
bool cmp2(L a,L b)
{
      return a.sy==b.sy?a.sx<b.sx:a.sy<b.sy;
}

int f[MAXN];


int Find(int x)
{
      return f[x]==x?x:f[x]=Find(f[x]);
}

void he_x()
{
      for(int i=0,j=1;i<n;++i)
      {
            if(L1[i].sx==L1[j].sx)
            {
                  while(L1[i].sx==L1[j].sx)
                  {
                        int a=Find(L1[i].id);
                        int b=Find(L1[j].id);
                        if(a!=b)
                        {
                              f[a]=b;
                        }
                        ++i;
                        ++j;
                  }
            }
      }
}


void he_y()
{
      for(int i=0,j=1;i<n;++i)
      {
            if(L2[i].sy==L2[j].sy)
            {
                  while(L2[i].sy==L2[j].sy)
                  {
                        int a=Find(L2[i].id);
                        int b=Find(L2[j].id);
                        if(a!=b)
                        {
                              f[a]=b;
                        }
                        ++i;
                        ++j;
                  }
            }
      }
}


LL Counter(int x)
{
      LL ans=0;
      for(int i=0;i<n;++i)
      {
            if(Find(L1[i].id) == Find(L1[x].id))
            {
                  ans+= A[i];
            }
      }
      return ans;
}

int answer[MAXN];

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d",&n))
      {
            for(int i=0;i<n;++i)
            {
                  int x,y,w,h;
                  scan2(x,y),scan2(w,h);
                  L1.push_back(L(x,y,x,y+h,i)); // shu
                  L1.push_back(L(x+w,y,x+w,y+h,i));
                  L2.push_back(L(x,y,x+w,y,i));  // heng
                  L2.push_back(L(x,y+h,x+w,y+h,i));
                  A[i]=w*h;
                  answer[i]=0;
            }
            sort(L1.begin(),L1.end(),cmp1);
            sort(L2.begin(),L2.end(),cmp2);
            for(int i=0;i<MAXN;++i) { f[i]=i; }
            int ans=INT_MIN,tmp;
            for(int i=0;i<n;++i)
            {
                  answer[Find(i)]+=A[i];
//                  tmp=Counter(i);
//                  ans=ans>tmp?ans:tmp;
            }
            for(int i=0;i<n;++i)
            {
                  ans=max(ans,answer[i]);
            }
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
