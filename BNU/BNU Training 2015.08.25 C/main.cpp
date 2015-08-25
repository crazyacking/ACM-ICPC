/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-25-21.41
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
typedef __int64(LL);
typedef unsigned __int64(ULL);
const double eps(1e-8);

const int MAXN=100020*2;
char s1[MAXN],s2[2];

/*
* 求a[i...len-1]和b的最长公共前缀有多长。
* 先对b进行自匹配再与a匹配。
* eKMP[i]就是对应答案。
* p[i]是b[i...len-1]和b的最长公共前缀有多长。
*/
int eKMP[MAXN],p[MAXN];
void E_KMP(char *a,char *b)
{
      //自匹配过程
      int la=strlen(a),lb=strlen(b),j=0;
      while(j<lb&&b[j]==b[j+1]) ++j;
      p[0]=lb,p[1]=j;
      int k=1;
      for(int i=2; i<lb; ++i)
      {
            int Len=k+p[k]-1,L=p[i-k];
            if(L<Len-i+1)
                  p[i]=L;
            else
            {
                  j=max(0,Len-i+1);
                  while(i+j<lb&&b[i+j]==b[j]) ++j;
                  p[i]=j,k=i;
            }
      }
      // b与a的匹配过程
      j=0;
      while(j<la && j<lb && a[j]==b[j]) ++j;
      eKMP[0]=j;
      k=0;
      for(int i=1; i<la; ++i)
      {
            int Len=k+eKMP[k]-1,L=p[i-k];
            if(L<Len-i+1)
                  eKMP[i]=L;
            else
            {
                  j=max(0,Len-i+1);
                  while(i+j<la&&j<lb && a[i+j]==b[j]) ++j;
                  eKMP[i]=j,k=i;
            }
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      for(int Cas=1; Cas<=t; ++Cas)
      {
            scanf("%s",s1);
            int len=strlen(s1);
            for(int i=0;i<len;++i)
                  s1[i+len]=s1[i];
            s1[len<<1]='\0';
            E_KMP(s2,s1); // 我用的是p[]数组,所以和s2无关
            int min_cycle;
            for(int i=1;i<=len;++i)
            {
                  if(i+p[i]>=len)
                  {
                        min_cycle=len%i?len:i;
                        break;
                  }
            }

            int L=0,E=0,G=0;
            for(int i=0;i<min_cycle;++i)
            {
                  if(p[i]>=len) ++E;
                  else
                  {
                        if(s1[i+p[i]]>s1[p[i]]) ++G;
                        else ++L;
                  }
            }
            printf("Case %d: %d %d %d\n",Cas,L,E,G);
      }
      return 0;
}
