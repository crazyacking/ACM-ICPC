/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-21-18.53
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

const int MAXN=50010;
LL n;
int r[MAXN],a[MAXN],M;
int quickPow(int a,LL b,int m)
{
      int ans=1;
      while(b)
      {
            if(b&1) { ans=(ans*a)%m,b--; }
            b>>=1,a=a*a%m;
      }
      return ans;
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL T;
      cin>>T;
      for(int Cas=1;Cas<=T;++Cas)
      {
            cin>>n>>M;
            a[0]=2%M,a[1]=10%M;
            if(!r[M])
            {
                  for(int i=2;;++i)
                  {
                        a[i]=(10*a[i-1]%M-a[i-2]+M)%M;
                        if(a[i-1]==a[0] && a[i]==a[1])
                        {
                              r[M]=i-1;
                              break;
                        }
                  }
            }
            int p=(quickPow(2,n,r[M])+1)%r[M];
            for(int i=2;i<=p;++i) a[i]=(10*a[i-1]%M-a[i-2]+M)%M;
            cout<<"Case #"<<Cas<<": "<<(a[p]-1+M)%M<<endl;
      }
      return 0;
}
/*

*/
