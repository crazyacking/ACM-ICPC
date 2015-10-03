/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-03-21.10
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

vector<int> ve;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,k;
      scanf("%d %d",&n,&k);
      LL ans=0;
      int tmp;
      for(int i=0;i<n;++i)
      {
            scanf("%d",&tmp);
            ans+=tmp/10;
            ve.push_back(tmp%10);
      }
      sort(ve.begin(),ve.end());
      for(int i=ve.size()-1;i>=0;--i)
      {
            if(k-(10-ve[i])>=0)
            {
                  k-=(10-ve[i]);
                  ++ans;
            }
            else break;
      }
      ans+=k/10;
      ans=min(ans,(LL)n*10);
      printf("%I64d\n",ans);
      return 0;
}
/*

*/
