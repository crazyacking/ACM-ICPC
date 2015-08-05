/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-04-21.03
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

int getCycle(int x) {
      if(x>=19&&x<=54) return (x-19)/18+4;
      else if(x>=55 && x<=86) return 6;
      else {
            if(x>=1 && x<=2) return 1;
            else if(x>=3 && x<=10) return 2;
            else return 3;
      }
}

int main() {
      int n,m,a[87];
      for(int i=1; i<=86; ++i) a[i]=i;
      swap(a[5],a[4]),swap(a[7],a[8]),swap(a[13],a[12]),swap(a[15],a[16]);
      while(cin>>n>>m) {
            if(getCycle(n)==getCycle(m)) {
                  if(a[n]>a[m]) puts("FIRST BIGGER");
                  else puts("SECOND BIGGER");
            } else {
                  if(n>m) puts("SECOND BIGGER");
                  else puts("FIRST BIGGER");
            }
      }
      return 0;
}
