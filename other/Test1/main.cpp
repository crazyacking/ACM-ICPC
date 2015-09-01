/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-31-19.55
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

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      multiset<int> ms;
      int tmp;
      for(int i=0;i<5;++i)
      {
            cin>>tmp;
            ms.insert(tmp);
      }
      cin>>tmp;

      ms.erase(ms.find(tmp));
      auto ptr=ms.begin();
      for(;ptr!=ms.end();++ptr)
      {
            printf("%d ",*ptr);
      }
      putchar(10);
      return 0;
}
/*

*/
