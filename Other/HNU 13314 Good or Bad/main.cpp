/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-27-08.27
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

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      char s[500];
      int t;
      scanf("%d",&t);
      getchar();
      while(t--)
      {
            gets(s);
            int len=strlen(s);
            int g=0,b=0;
            for(int i=0;i<len;++i)
            {
                  if(s[i]=='g'||s[i]=='G') g++;
                  if(s[i]=='b'||s[i]=='B') b++;
            }
            printf("%s",s);

            if(g>b) puts(" is GOOD");
            else if(g<b) puts(" is A BADDY");
            else puts(" is NEUTRAL");
      }
      return 0;
}
/*

*/
