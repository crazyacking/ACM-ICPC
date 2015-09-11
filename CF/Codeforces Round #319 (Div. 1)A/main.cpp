/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-11-16.33
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
const int NN=100100;

int p[NN];
bool v[NN];
int num=-1;
void makePrime()
{
      int i,j;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
}
vector<int> ve;
int n;
int main()
{
      makePrime();
      scanf("%d",&n);
      for(int i=0;i<num;++i)
      {
            if(p[i]<=n)
            {
                  int t=p[i];
                  while(t<=n)
                  {
                        ve.push_back(t);
                        t=t*p[i];
                  }
            }
            else break;
      }
      int si=ve.size();
      printf("%d\n",si);
      for(int i=0;i<si;++i)
            printf(i==si-1?"%d\n":"%d ",ve[i]);
      return 0;
}
/*

*/
