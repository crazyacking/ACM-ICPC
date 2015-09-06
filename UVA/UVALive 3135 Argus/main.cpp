/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-06-15.36
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

struct item
{
      int qNum,Per,Time;
      bool operator <(const item &a) const
      {
            return Time > a.Time || (Time == a.Time && qNum > a.qNum);
      }
};

int main()
{
      priority_queue<item> pq;
      char a[20];
      while(scanf("%s",a) != EOF && a[0] != '#')
      {
            item it;
            scanf("%d%d",&it.qNum,&it.Per);
            it.Time = it.Per;
            pq.push(it);
      }
      int K;
      scanf("%d",&K);
      while(K--)
      {
            item r = pq.top();
            pq.pop();
            printf("%d\n",r.qNum);
            r.Time += r.Per;
            pq.push(r);
      }
      return 0;
}
