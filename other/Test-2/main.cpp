/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-19-10.07
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

/** O(n)内求出所有回文串
 *原串 :abaaba
 *Ma串 :.,a,b,a,a,b,a,
 *Mp[i]:Ma串中，以字符Ma[i]为中心的最长回文子串的半径长度(包括Ma[i],也就是把回文串对折后的长度).
 ****经过对原串扩展处理后，将奇数串的情况也合并到了偶数的情况(不需要考虑奇数串)
 */
const int MAXN=110010;
char Ma[MAXN*2],s[MAXN];
int Mp[MAXN*2],Mplen;
void Manacher(char s[],int len)
{
      int le=0;
      Ma[le++]='.';
      Ma[le++]=',';
      for(int i=0;i<len;++i)
      {
            Ma[le++]=s[i];
            Ma[le++]=',';
      }
      Mplen=le;
      Ma[le]=0;
      int pnow=0,pid=0;
      for(int i=1;i<le;++i)
      {
            if(pnow>i)
                  Mp[i]=min(Mp[2*pid-i],pnow-i);
            else
                  Mp[i]=1;
            for(;Ma[i-Mp[i]]==Ma[i+Mp[i]];++Mp[i]);
            if(i+Mp[i]>pnow)
            {
                  pnow=i+Mp[i];
                  pid=i;
            }
      }
}

long long gcd(long long a,long long b)
{
      return !b?a:gcd(b,a%b);
}
long long gcd(long long a,long long b)
{
      return !b?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
      return a*b/gcd(a,b);
}
/** Lucas
 * p必须是小于100010的质数
 */
using namespace std;
long long F[100010];
void init(long long p)
{
      F[0] = 1;
      for(int i = 1; i <= p; i++)
            F[i] = F[i-1]*i%p;
}
long long inv(long long a,long long m)
{
      if(a == 1)return 1;
      return inv(m%a,m)*(m-m/a)%m;
}
long long Lucas(long long n,long long m,long long p)
{
      long long ans = 1;
      while(n&&m)
      {
            long long a = n%p;
            long long b = m%p;
            if(a < b)return 0;
            ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
            n /= p;
            m /= p;
      }
      return ans;
}

int main()
{
      int T;
      int n,m,p;
      scanf("%d",&T);
      while(T--)
      {
            scanf("d%d",&n,&m,&p);
            init(p);
            printf("%d\n",(int)Lucas(n,m,p));
      }
     return 0;
}
|
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s",s))
      {
            Manacher(s,strlen(s));
            int ans=1,idx=0;
            for(int i=0;i<Mplen;++i)
            {
                  if(Mp[i]>ans)
                  {
                        ans=Mp[i],idx=i;
                  }
            }
            cout<<ans-1<<endl;
      }
      return 0;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      
      return 0;
}
/*

*/