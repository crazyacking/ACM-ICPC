/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-28-08.23
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
char s[MAXN];
int Next[MAXN];
void getNext(int len)
{
      Next[0]=0;
      for(int i=1,k=0;i<len;++i)
      {
            while(s[i]!=s[k] && k) k=Next[k-1];
            if(s[i]==s[k]) ++k;
            Next[i]=k;
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s",s) && s[0]!='.')
      {
            int len=strlen(s);
            getNext(len);
            int min_cycle=len-Next[len-1];
            if(len%min_cycle!=0) printf("1\n");
            else printf("%d\n",len/min_cycle);
      }
      return 0;
}
/*

*/
