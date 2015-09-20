/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-19-17.10
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
typedef unsigned long long(ULL);
const double eps(1e-8);


#define N 2
#define ll long long

struct Matrix
{
      ll v[N][N];
};

Matrix A,B= {1L,0L,0L,1L};
ll M;


ULL mul_mod (ULL a, ULL b, ULL c) //利用快速取幂模的思想求a*a%c和res*a%c，为了防止溢出
{
    ULL res = 0;
    for ( ; b; b >>= 1)
    {
        if (b & 1)
        {
            res += a;    //这两句换成 res = (res + a) % c 会很慢
            if (res >= c) res -= c;
        }
        a <<= 1;    //这两句换成 a = (a + a) % c 也很慢
        if (a >= c) a -= c;
    }
    return res;
}

Matrix mul(Matrix m1,Matrix m2,ll M)
{
      int i,j,k;
      Matrix c;
      for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
            {
                  c.v[i][j] = 0;
                  for(k = 0; k < N; k++)
                  {
                        c.v[i][j] += mul_mod((ULL)m1.v[i][k],(ULL)m2.v[k][j],(ULL)M);
                        c.v[i][j] %= M;
                  }
                  c.v[i][j] %= M;
            }
      return c;
}

Matrix Mpow(Matrix A,Matrix B,ll n,ll M)
{
      Matrix x = A,c = B;
      while(n >= 1)
      {
            if(n&1L)c = mul(c,x,M);
            n >>= 1;
            x = mul(x,x,M);
      }
      return c;
}

int main()
{
      ll n, a, b, t;
      a=5,b=24;
      while(cin>>n>>M)
      {
            n=(1ll<<n)+1;
            if(n == 1)
            {
                  cout << (2*(a%M)) % M <<endl; continue;
            }
            if(n == 2)
            {
                  cout << ((2*((a%M)*(a%M))%M)%M + (2*b)%M) % M <<endl; continue;
            }
            A.v[0][0] = (2*(a%M)) % M;
            t = a;
            t *= a;
            A.v[0][1] = 1;
            t = b - t;
            while(t < 0)t += M;
            A.v[1][0] = t;
            A.v[1][1] = 0;
            Matrix p = Mpow(A,B,n-2,M), q = {((2*((a%M)*(a%M))%M)%M + (2*b)%M) % M, (2*(a%M)) % M, 0L, 0L};
            p = mul(q,p,M);
            cout<<p.v[0][0]<<endl;
      }
      return 0;
}
