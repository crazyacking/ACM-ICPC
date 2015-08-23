#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define mod 1000000007
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0]
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef long long LL;
const int N = 1000005;
int t , n;
LL phi[N] , ans[N];
void Init()
{
      for(int i = 2 ; i < N ; i ++)
      {
            if(phi[i]) continue;
            for(int j = i ; j < N ; j += i)
            {
                  if(!phi[j]) phi[j] = j;
                  phi[j] = phi[j] * 1LL / i * (i - 1);
            }
      }
      ans[1] = 1LL;
      for(int i = 2 ; i < N ; i ++)
            ans[i] = ((1LL * i * i * phi[i] >> 1) + i)%mod;
      for(int i = 2 ; i * i < N ; i ++)
      {
            ans[i * i] += 1LL * i * i * phi[i] * i >> 1;
            ans[i * i]%=mod;
            for(int j = i * i + i , k = i + 1 ; j < N ; j += i , k ++)
            {
                  ans[j] += (1LL * j * phi[i] * i >> 1) + (1LL * j * k * phi[k] >> 1);
                  ans[j]%=mod;
            }
      }
}
int main()
{
      Init();
      scanf("%d" , &t);
      while(t --)
      {
            scanf("%d" , &n);
            printf("%lld\n" , ans[n]%mod);
      }
      return 0;
}
