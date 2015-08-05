/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-06-01.42
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
#include <ctime>
#include <cstring>
#define  LL long long
#define  ULL unsigned long long
using namespace std;
const int N=5000;
const int M=1000000000;
int main()
{
//      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","w",stdout);
      int t=1;
      while(t--)
      {
            srand(time(NULL));
            LL n=200000,k=8;
            printf("%lld %lld\n",n,k);
            for(int i=0;i<n;++i)
            {
                  LL tmp=rand()%M;
                  printf("%lld ",tmp);
            }
            puts("");
      }
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      return 0;
}
/*

*/
