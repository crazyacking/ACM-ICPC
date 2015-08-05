/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-04-19.00
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
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      while(~scanf("%d",&n)) {
            getchar(); char s[20]; multiset<int> ms;
            for(int i=0; i<n; ++i) {
                  gets(s);
                  bool f=0;
                  for(int i=0; i<strlen(s); ++i) {
                        if(s[i]==' ') { f=true; break; }
                  }
                  int a,b;
                  if(f) {
                        sscanf(s,"%d %d",&a,&b);
                        ms.insert(b);
                  } else {
                        sscanf(s,"%d",&a);
                        if(a==2) { if(ms.size()>0) ms.erase(*ms.begin());}
                        else {
                              if(ms.size()>0) printf("%d\n",*(--ms.end()));
                              else puts("0");
                        }
                  }
            }
      }
      return 0;
}
/*

*/
