/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-10-20.11
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

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL a4[30];
      for(int i=1;i<=29;++i)
      {
            a4[i]=pow((LL)i,4LL);
            printf("%2d : %5lld\n",i,a4[i]);
      }
      puts("");

      puts("-----------------------------------------------------------------");
      LL sum=0;
      LL ss1[30];
      puts("ss1");
      for(int i=1;i<=29;++i)
      {
            sum+=a4[i];
            ss1[i]=sum;
            printf("%2d : %5lld\n",i,ss1[i]);
      }

      LL ss2[30];
      puts("ss2");
      for(int i=1;i<=28;++i)
      {
            ss2[i]=ss1[i+1]-ss1[i];
            printf("%2d : %5lld\n",i,ss2[i]);
      }

      puts("");

      puts("-----------------------------------------------------------------");

      LL ss3[30];
      for(int i=1;i<=27;++i)
      {
            ss3[i]=ss2[i+1]-ss2[i];
            printf("%2d : %5lld\n",i,ss3[i]);
      }

      puts("");

      puts("-----------------------------------------------------------------");

      LL ss4[30];
      for(int i=1;i<=26;++i)
      {
            ss4[i]=ss3[i+1]-ss3[i];
            printf("%2d : %5lld\n",i,ss4[i]);
      }

      puts("");

      puts("-----------------------------------------------------------------");

      LL ss5[30];
      for(int i=1;i<=25;++i)
      {
            ss5[i]=ss4[i+1]-ss4[i];
            printf("%2d : %5lld\n",i,ss5[i]);
      }
      puts("");

//      puts("-----------------------------------------------------------------");
//

//
//      LL ss6[30];
//      for(int i=1;i<=24;++i)
//      {
//            ss6[i]=ss5[i+1]-ss5[i];
//            printf("%2d : %5lld\n",i,ss6[i]);
//      }
//      puts("");
//
//      puts("-----------------------------------------------------------------");

//      LL ss7[30];
//      for(int i=1;i<=23;++i)
//      {
//            ss7[i]=ss6[i+1]-ss6[i];
//            printf("%2d : %5lld\n",i,ss7[i]);
//      }
//      puts("");
//
//      puts("-----------------------------------------------------------------");
      return 0;
}
/*

*/
