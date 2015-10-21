/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-03-14.45
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
struct st
{
      int r,c,s,d,t;
};
int n;
st cnt(st a)
{
      if(a.d==0)
      {
            if(a.r-a.s<1)
            {
                  int t=a.s-(a.r-1);
                  if(t/n%2==0)
                        a.d=2;
            }
            a.r-=a.s;
      }
      else if(a.d==1)
      {
            if(a.c+a.s>n)
            {
                  int t=a.s-(n-a.c);
                  if(t/n%2==0)
                        a.d=3;
            }
            a.c+=a.s;
      }

      else if(a.d==2)
      {
            if(a.r+a.s>n)
            {
                  int t=a.s-(n-a.r);
                  if(t/n%2==0)
                        a.d=0;
            }
            a.r+=a.s;
      }
      else
      {
            if(a.c-a.s<1)
            {
                  int t=a.s-(a.c-1);
                  if(t/n%2==0)
                        a.d=1;
            }
            a.c-=a.s;
      }
      a.r=(a.r%(n-1)+n)%n+1;
      a.c=(a.c%n+n)%n+1;
      return a;
}
st cg(st a)
{
      a.d=((a.d-1)%4+4)%4;
      return a;
}
void work(int tm,st a,st b)
{
      for(int i=1;i<=tm;i++)
      {
            printf("%d %d %d %d\n",a.r,a.c,b.r,b.c);
            int ta=a.d,tb=b.d;
            a=cnt(a);
            b=cnt(b);
            if(a.r==b.r&&a.c==b.c)
            {
                  a.d=tb;
                  b.d=ta;
                  continue;
            }
            if(i%a.t==0)
                  a=cg(a);
            if(i%b.t==0)
                  b=cg(b);
      }
      printf("%d %d %d %d\n",a.r,a.c,b.r,b.c);
}
int main()
{
      while(scanf("%d",&n)!=EOF)
      {
            char s[10];
            st a,b;
            a.r=a.c=1;
            b.r=b.c=n;
            scanf("%s%d%d",s,&a.s,&a.t);
            if(s[0]=='N')
                  a.d=0;
            else if(s[0]=='E')
                  a.d=1;
            else if(s[0]=='S')
                  a.d=2;
            else
                  a.d=3;
            scanf("%s%d%d",s,&b.s,&b.t);
            if(s[0]=='N')
                  b.d=0;
            else if(s[0]=='E')
                  b.d=1;
            else if(s[0]=='S')
                  b.d=2;
            else
                  b.d=3;
            int tm;
            scanf("%d",&tm);
            work(tm,a,b);
      }
}
