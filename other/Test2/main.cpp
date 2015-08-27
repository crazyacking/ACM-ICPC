/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-25-23.41
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
typedef __int64(LL);
typedef unsigned __int64(ULL);
const double eps(1e-8);

LL get_eular(LL m)
{
     LL ret=1;
     for(LL i=2; i*i<=m; i++)
           if(m%i==0)
           {
                 ret*=i-1;
                 m/=i;
                 while(m%i==0)
                  
                 {
                       m/=i;
                       ret*=i;
                 }
           }
     if(m>1) ret*=m-1;
     return ret;
}

long long Quickpow(long long a,long long b,long long m)
{
     long long ans=1;
     while(b)
     {
           if(b&1) { ans=(ans*a)%m,b--; }
           b/=2,a=a*a%m;
     }
     return ans;
}
const int mod=1000000007;
int main()
{
//      cout<<get_eular(200LL)<<endl;
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int A,x;
      while(cin>>A>>x)
      {
            cout<<Quickpow(A,(x%get_eular(200LL)+get_eular(200LL)),200)<<endl;;
            cout<<Quickpow(A,x,200)<<endl;

      }
      return 0;
}
/*

*/
