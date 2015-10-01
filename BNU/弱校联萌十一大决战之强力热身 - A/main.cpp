/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-01-08.59
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

const int MAXN=1e5+10;
bool f[MAXN];


// pre work
set<int> se;
void pre()
{
      int up=sqrt(1e9+100);
      for(int i=0; i<=up; ++i)
      {
            se.insert(i*i);
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      pre();
      int n;
      while(~scanf("%d",&n))
      {
            int tmp;
            bool flag=true;
            for(int i=0; i<n; ++i)
            {
                  scanf("%d",&tmp);
                  if(se.find(tmp)==se.end())
                  {
                        flag=false;
                  }
            }
            if(flag)
                  puts("Yes");
            else puts("No");
      }
      return 0;
}
/*

*/
