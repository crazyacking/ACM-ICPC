#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define LL long long
#define sz( a ) int( a.size() )
#define all( a ) a.begin(), a.end()
#define sd second
#define ft first
const int N = 100005;
const int Mod = (int) 1e9 + 7;

int n, m;
int s[N], t[N];
LL f[N];
vector<int> q[N];
int main()
{
      for(int i = 1; i <= 100000; ++i)
      {
            s[i] = 1;
      }
      for(int i = 2; i <= 100000; ++i)
      {
            for(int j = i + i; j <= 100000; j += i)
            {
                  s[j] = max(s[j], i);
            }
      }
//
//      for(int i=1;i<=20;++i)
//      {
//            printf("%d ",s[i]);
//      }
//      puts("");
      for(int i = 2; i <= 100000; ++i)
      {
            f[i] = f[i - 1];
            if(s[i] == 1) t[i] = 1;
            int k = i, m = s[i];
            if(t[m] && t[k / m] && (m != k / m))
            {
                  t[i] = 1;
                  t[m] = 0, t[k / m] = 0;
                  f[i] += m ;
                  f[i] += k / m - 1;
            }
            else
            {
                  f[i] += s[i];
            }
      }
      while(~scanf("%d", &n))
      {
            printf("%I64d\n", f[n]);
      }
}
