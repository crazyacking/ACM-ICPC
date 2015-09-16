/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-16-11.12
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
int n,m;
int Mp[20][20],Mt[20][20],ans[20][20];
int dx[]= {0,1,0,-1, 0};
int dy[]= {0,0,1, 0,-1};
int get(int x,int y)
{
      int ret=Mp[x][y];
      for(int i=0; i<5; ++i)
      {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if((xx>=0&&xx<n)&&(yy>=0&&yy<m))
                  ret+=Mt[xx][yy];
      }
      return ret&1;
}
int work(int x)
{
      int ct=0,num=0;
      for(int i=0; i<m; ++i)
            if(x>>i&1)
                  Mt[0][i]=1,++num;
      for(int i=1; i<n; ++i)
            for(int j=0; j<m; ++j)
                  if(get(i-1,j))
                        Mt[i][j]=1,++num;
      for(int i=0; i<m; ++i)
            if(get(n-1,i)) return INT_MAX;
      return num;
}
int main()
{
      while(~scanf("%d %d",&n,&m))
      {
            for(int i=0; i<n; ++i)
                  for(int j=0; j<m; ++j)
                        scanf("%d",&Mp[i][j]);
            int statue=1<<m;
            int MN=INT_MAX;
            for(int i=0; i<statue; ++i)
            {
                  memset(Mt,0,sizeof Mt);
                  int tmp=work(i);
                  if(tmp<MN)
                  {
                        MN=tmp;
                        for(int i=0; i<n; ++i)
                              for(int j=0; j<m; ++j)
                                    ans[i][j]=Mt[i][j];
                  }
            }
            if(MN==INT_MAX)
            {
                  puts("IMPOSSIBLE");
                  continue;
            }
            for(int i=0; i<n; ++i)
                  for(int j=0; j<m; ++j)
                        printf(j==m-1?"%d\n":"%d ",ans[i][j]);
      }
      return 0;
}
/*

*/
