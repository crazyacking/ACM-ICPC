/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-06-12.20
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
map<int,vector<int> > mp;
// map<key,val> : key相当于下标map,即：mp[key]=val;
int main()
{
      int n,m,k,x;
      while(~scanf("%d %d",&n,&m))
      {
            mp.clear();
            for(int i=1;i<=n;++i)
            {
                  scanf("%d",&x);
                  if(!mp.count(x)) mp[x]=vector<int>();
                  mp[x].push_back(i);
            }
            while(m--)
            {
                  scanf("%d %d",&k,&x);
                  if(!mp.count(x) || k>mp[x].size()) puts("0");
                  else printf("%d\n",mp[x][k-1]);
            }
      }
      return 0;
}
/*

*/
