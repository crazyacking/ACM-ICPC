/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-28-22.57
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
      int n,f;
      scanf("%d %d",&n,&f);
      int ans=0,tmp;
      for(int i=0;i<n;++i)
      {
            scanf("%d",&tmp);
            ans+=tmp/10;
            tmp%=10;
            if(tmp!=0) ve.push_back(tmp);
      }
      sort(ve.begin(),ve.end());
      int si=ve.size();
      for(int i=si-1;i>=0;--i)
      {
            if(f-(10-ve[i])>=0)
            {
                  ans++;
                  f-=(10-ve[i]);
            }
            else break;
      }
      if(f>0)
      {
            ans+=f/10;
      }
      if(ans>n*10) ans=n*10;
      cout<<ans<<endl;
      return 0;
}
/*

*/
