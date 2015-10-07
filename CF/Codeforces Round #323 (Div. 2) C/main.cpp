/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-05-10.54
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

map<int,int> mp;
vector<int> a;
vector<int> ans;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,tmp;
      scanf("%d",&n);
      for(int i=0; i<n*n; ++i)
      {
            scanf("%d",&tmp);
            a.push_back(tmp);
            mp[tmp]++;
      }
      sort(a.begin(),a.end());
      int si=a.size();
      ans.push_back(a[si-1]);
      mp[a[si-1]]--;
      for(int i=si-2; i>=0; --i)
      {
            while(mp[a[i]]<=0 &&i>=0) --i;
            if(i<0) break;
            ans.push_back(a[i]);
            for(int j=0; j<ans.size()-1; ++j)
            {
                  mp[__gcd(ans[j],a[i])]-=2;
            }
            mp[a[i]]--;
      }
      for(int i=0; i<ans.size(); ++i)
      {
            printf("%d ",ans[i]);
      }
      putchar(10);
      return 0;
}
/*

*/
