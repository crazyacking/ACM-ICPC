/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-16-16.06
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



const int MAXN= 1010;
int N,M,K;

char s1[MAXN],s2[MAXN],ps2[MAXN],res[40];

void init()
{
      int i;
      for(i=0;i<=9;++i)
      {
            res[i]=i+'0';
      }
      for(i=10;i<36;++i)
      {
            res[i]='A'+i-10;
      }
      res[36]='\0';

}
bool se[MAXN][40];
int main()
{
      init();
      while(scanf("%d %d %d",&N,&M,&K),N+M+K)
      {
            memset(ps2,'0',sizeof ps2);
            for(int i=0;i<M;++i)
            {
                  for(int j=0;j<N;++j)
                  {
                        se[i][j]=true;
                  }
            }
            for(int i=0;i<K;++i)
            {
                  scanf("%s%s",s1,s2);
                  for(int j=0;j<N;++j)  // 判断每个开关和上一次的状态是否改变
                  {
                        if(s1[j]=='1') // 如果改变
                        {
                              for(int k=0;k<M;++k)
                              {
                                    if(s2[k]==ps2[k]) se[k][j]=false;
                              }
                        }
                        else// 未改变
                        {
                              for(int k=0;k<M;++k)
                              {
                                    if(s2[k]!=ps2[k]) se[k][j]=false;
                              }
                        }
                  }
                  strcpy(ps2,s2);
            }
            int cnt=0,idx=0;
            for(int i=0;i<M;++i)
            {
                  cnt=0,idx=0;
                  for(int j=0;j<N;++j)
                  {
                        if(se[i][j]==true)
                        {
                              ++cnt;
                              idx=j;
                        }
                  }
                  if(cnt!=1)
                  {
                        printf("?");
                  }
                  else
                  {
                        printf("%c",res[idx]);
                  }
            }
            puts("");

      }
      return 0;
}
/*

*/
