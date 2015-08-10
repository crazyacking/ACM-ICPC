//div1B 定义元素在R^2上的等价关系，等价关系是自反(a=a)、对称(a=b则b=a)、传递(a=b且b=c那么a=c)的，求出有多少个集合是对称、传递但不自反的且元素个数为n，答案模10^9+7
//n<=4000

//（对称、传递但不自反可以被看作是存在a缺少a和其他东西的等价





//div1B 问有多少个有向图满足：
//如果有u->v则有v->u
//如果有u->v,v->w则有u->w
//存在一个u，没有u->u
//点数n，答案模10^9+7


/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-11-02.03
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
#define mod 1000000007
#define  LL long long
#define  ULL unsigned long long
using namespace std;
const int MAXN=4050;
LL c[MAXN][MAXN];
LL B[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL n;
      cin>>n;
      {
            for(int i=0;i<=n;++i)
            {
                  c[i][0]=1;
            }
            for(int i=1;i<=n;++i)
            {
                  for(int j=1;j<=n;++j)
                  c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
            }
            B[0]=1;
            B[1]=1;
            LL ans=0;
            for(int i=2;i<=n;++i)
            {
                  for(int k=0;k<i;++k)
                        B[i]=(B[i]+1LL*c[i-1][k]*B[k]%mod)%mod;
            }
            for(int i=1;i<=n;++i)
                  ans=(ans+1LL*c[n][i]*B[n-i]%mod)%mod;
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
