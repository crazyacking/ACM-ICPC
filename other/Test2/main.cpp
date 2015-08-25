/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-25-22.07
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
const int MAXN = 10^100000*2;
char S[MAXN];
int  ex[MAXN];

void getNext(char* T, int* next)
{
      int len=strlen(T), a=0;
      next[0] = len;
      while(a<len-1 && T[a]==T[a+1]) ++a;
      next[1] = a;
      a=1;
      for(int k=2; k<len; ++k)
      {
            int p=a+next[a]-1, L=next[k-a];
            if(k-1+L >= p)
            {
                  int j = max(p-k+1, 0);
                  while(k+j<len && T[k+j]==T[j]) ++j;
                  next[k] = j;
                  a=k;
            }
            else
                  next[k] = L;
      }
}

int main()
{
      int cas=1,nCase;
      scanf("%d",&nCase);
      while(nCase--)
      {
            scanf("%s",S);
            int len=strlen(S);
            for(int i=0; i<len; ++i)
            {
                  S[i+len] = S[i];
            }
            S[2*len] = '\0';
            getNext(S,ex);
            int L=0, E=0, G=0;
            // 拓展KMP求最短循环节
            int kk;
            for(int i=1; i<=len; ++i)
            {
                  if(i+ex[i]>=len)
                  {
                        kk = len%i?len:i;
                        break;
                  }
            }
            for(int i=0; i<kk; ++i)
            {
                  if(ex[i]>=len)
                        ++E;
                  else
                  {
                        if(S[i+ex[i]] > S[ex[i]])
                              ++G;
                        else
                              ++L;
                  }
            }
            printf("Case %d: %d %d %d\n",cas++,L,E>0,G);
      }
      return 0;
}
