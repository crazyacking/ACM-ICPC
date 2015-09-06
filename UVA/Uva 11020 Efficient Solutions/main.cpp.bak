/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-06-10.28
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

struct point
{
      int x,y;
      point(){}
      point(int xx,int yy):x(xx),y(yy){}
      bool operator <(const point& a) const
      {
            return x<a.x ||(x==a.x && y<a.y);
      }
};
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t,Cas;
      scanf("%d",&t);
      multiset<point> ms;
      for(int Cas=1;Cas<=t;++Cas)
      {
            if(Cas>1) puts("");
            printf("Case #%d:\n",Cas);
            int n,x,y;
            ms.clear();
            scanf("%d",&n);
            while(n--)
            {
                  scanf("%d %d",&x,&y);
                  auto it=ms.lower_bound(point(x,y));
                  if(it == ms.begin() || (--it)->y >y)
                  {
                        ms.insert(point(x,y));
                        it=ms.upper_bound(point(x,y));
                        while(it!=ms.end() && it->y>=y) ms.erase(it++);
                  }
                  printf("%d\n",ms.size());
            }
      }
      return 0;
}
/*

*/
