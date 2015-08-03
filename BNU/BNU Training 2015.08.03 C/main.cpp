/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-03-12.40
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

int main() {
      int n,t,s,i,se[105];
      double tmp;
      scanf("%d %d %d",&n,&t,&s);
      for(i=0; i<n; i++)
            scanf("%d",&se[i]);
      for(i=0; i<n; i++) {
            tmp=(s+t+se[i])*1.0/2;
            printf("%.6lf\n",tmp);
      }
      return 0;
}
