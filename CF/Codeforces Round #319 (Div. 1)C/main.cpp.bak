/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-11-16.00
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

const int N = 1010;
int n;
vector<pair<int,int> > X[N];
vector<int> res;
int main()
{
      scanf("%d",&n);
      for(int i=0;i<n;++i)
      {
            int x,y;
            scanf("%d %d",&x,&y);
            X[x/1000].push_back(make_pair(y,i));
      }
      for(int i=0;i<=1000;++i)
      {
            sort(X[i].begin(),X[i].end());
            if(i&1)
                  reverse(X[i].begin(),X[i].end());
            for(auto &it:X[i])
                  printf("%d ",1+it.second);
      }
      return 0;
}
