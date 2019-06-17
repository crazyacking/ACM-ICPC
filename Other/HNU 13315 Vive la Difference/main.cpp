/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-27-08.48
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
      int t;
      cin>>t;
      while(t--)
      {
            int cas;
            cin>>cas;
            int n;
            cin>>n;
            char s[1010];
            cin>>s;
            printf("%d ",cas);
            int len=strlen(s);
            for(int i=0;i<len;++i)
            {
                  for(int j=0;j<n;++j)
                  {
                        printf("%c",s[i]);
                  }
            }
            puts("");
      }
      return 0;
}
/*

*/
