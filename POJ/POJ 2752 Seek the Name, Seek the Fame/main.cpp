/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-28-08.55
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
const int MAXN=400010;
int n;
char s[MAXN];
int Next[MAXN];
int ans[MAXN];
void getNext()
{
      Next[0]=0;
      for(int i=1,k=0;i<n;++i)
      {
            while(s[i]!=s[k]&& k) k=Next[k-1];
            if(s[i]==s[k]) ++k;
            Next[i]=k;
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s",s))
      {
            n=strlen(s);
            getNext();
            int k=n-1;
            int cnt=0;
            while(Next[k])
            {
                  ans[cnt++]=Next[k];
                  k=Next[k-1];
            }
            ans[cnt++]=n;
            sort(ans,ans+cnt);
            for(int i=0;i<cnt;++i)
            {
                  printf(i==cnt-1?"%d\n":"%d ",ans[i]);
            }
      }
      return 0;
}
/*

*/
