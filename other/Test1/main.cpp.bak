/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-21-10.20
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

const int MAXN=10010;
int next[MAXN];
char P[MAXN],T[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s %s",P,T))
      {
            kmp(P,T,next);
            for(int i=0;i<strlen(P);++i)
                  printf("%d ",next[i]);
            putchar(10);
      }
      return 0;
}
/*

*/
