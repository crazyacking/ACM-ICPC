/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-25-19.41
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

const int NN=1100;
int N,M;

struct node
{
      int s,w,c;
      bool operator <(node a) const
      {
            if(c==a.c) return w<a.w;
            return c<a.c;
      }
};
node a[NN];

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int T;
      cin>>T;
      while(T--)
      {
            cin>>N>>M;
            set<int> se;
            for(int i=0;i<N;++i)
            {
                  cin>>a[i].s>>a[i].w>>a[i].c;
                  se.insert(a[i].s);
            }
            if(se.size()<7)
            {
                  puts("-1");
                  continue;
            }
            sort(a,a+N);
            LL ti,mo;
            LL ans=0;
            for(int i1=0;i1<N;++i1)
            {
                  for(int i2=i1+1;i2<N;++i2)
                  {
                        if(a[i2].s==a[i1].s) continue;
                        for(int i3=i2+1;i3<N;++i3)
                        {
                              if(a[i3].s== a[i2].s || a[i3].s== a[i1].s) continue;
                              for(int i4=i3+1;i4<N;++i4)
                              {
                                    if(a[i4].s== a[i3].s || a[i4].s== a[i2].s || a[i4].s == a[i1].s) continue;
                                    for(int i5=i4+1;i5<N;++i5)
                                    {
                                          if(a[i5].s == a[i4].s || a[i5].s == a[i3].s||a[i5].s == a[i2].s||a[i5].s == a[i1].s) continue;
                                          for(int i6=i5+1;i6<N;++i6)
                                          {
                                                if(a[i6].s == a[i5].s|| a[i6].s == a[i4].s||a[i6].s == a[i3].s||a[i6].s == a[i2].s || a[i6].s == a[i1].s) continue;
                                                for(int i7=i6+1;i7<N;++i7)
                                                {
                                                      if(a[i7].s==a[i6].s || a[i7].s==a[i5].s || a[i7].s==a[i4].s || a[i7].s==a[i3].s || a[i7].s==a[i2].s || a[i7].s==a[i1].s) continue;
                                                      mo=0;mo+=( a[i1].w + a[i2].w + a[i3].w + a[i4].w + a[i5].w + a[i6].w + a[i7].w );
                                                      if(mo>M) continue;
                                                      ans+=( a[i1].c +  a[i2].c +  a[i3].c +  a[i4].c +  a[i5].c +  a[i6].c +  a[i7].c );break;

                                                }
                                          }
                                    }
                              }
                        }
                  }
            }
            cout<<ans<<endl;
      }

      return 0;
}
/*

*/
