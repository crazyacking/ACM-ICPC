/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-18-19.01
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

typedef long long LL;
const int maxn = 100010;
LL inv[maxn];
void getInv(LL p)
{
      inv[0] = 1;
      for(int i = 1; i <= p; i++) inv[i] = inv[i-1] * i % p;
}
LL pow_mod(LL a , LL n , LL m)
{
      if(n == 0) return 1;
      LL ret = pow_mod(a , n >> 1 , m);
      ret = ret * ret % m;
      if(n & 1) ret = ret * a % m;
      return ret;
}
//Lucas算法依次得到a[i]
LL lucas(LL n , LL m , LL p)
{
      getInv(p);
      LL ret = 1;
      while(n && m)
      {
            LL a = n % p , b = m % p;
            if(a < b) return 0;
            ret = (ret * inv[a] * pow_mod(inv[b] * inv[a-b] % p , p-2 , p)) % p;
            n /= p , m /= p;
      }
      return ret;
}
//扩展欧几里算法得求逆元
void ex_gcd(LL a , LL b , LL &d , LL &x , LL &y)
{
      if(!b) {d = a; x = 1; y = 0;}
      else {ex_gcd(b , a % b , d , y , x); y -= x * (a / b);}
}
//a * b % m
LL mul_mod(LL a , LL b , LL n)
{
      LL res = 0;
      while(b)
      {
            if(b & 1) res = (res + a) % n;
            a = (a + a) % n;
            b >>= 1;
      }
      return res;
}
//中国剩余定理合并答案
LL china(LL n , LL *a , LL *p)
{
      LL M = 1 , d  , y , x = 0;
      for(int i = 0; i < n; i++) M *= p[i];
      for(int i = 0; i < n; i++)
      {
            LL w = M / p[i];
            ex_gcd(p[i] , w , d , d , y);
            //y * w * a[i]会超LL，所以要mul_mod
            x = (x + mul_mod(y * w % M , a[i], M))%M;
      }
      return (x + M) % M;
}
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      LL m , n , k , t , p[20] , a[20];
      cin >> t;
      while(t--)
      {
            cin >> n >> m >> k;
            for(int i = 0; i < k; i++)
            {
                  cin >> p[i];
                  a[i] = lucas(n , m , p[i]);
            }
            cout << china(k , a , p) << endl;
      }
      return 0;
}
