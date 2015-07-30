/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-30-09.36
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


int a[1000050];
set<int> se;
int fun1(int gap)
{
      for(int i=0;i<n;++i)
      {
            if()
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                  scanf("%d",&a[i]);
                  se.insert(a[i]);
            }
            sort(a,a+n);
            int gap=0;
            int div=0;
            int ans=INT_MIN;
            for(int i=0;i<n;++i)
            {
                  for(int j=i+1;j<n;++j)
                  {
                        gap=a[j]-a[i];
                        div=a[j]/a[i];
                        ans=max(fun1(gap),fun2(div));
                  }
            }
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
