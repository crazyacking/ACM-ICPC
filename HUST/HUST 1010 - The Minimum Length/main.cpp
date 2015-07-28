/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-28-07.12
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
const int MAXN=1000010;
int n;
char s[MAXN];
int Next[MAXN];
void getNext()
{
      Next[0]=0;f
      for(int i=1,k=0;i<n;++i)
      {
            while(s[i]!=s[k]&&k) k=Next[k-1];
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
            int min_cycle=n-Next[n-1];
            printf("%d\n",min_cycle);
      }
      return 0;
}
/*

*/
