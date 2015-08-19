#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std ;
const int maxn = 1e5+10 ;
int a[maxn] ;
typedef long long ll ;
ll l[maxn] , r[maxn] ;
int main()
{
      int n , d1 , d2 ;
      while(~scanf("%d%d%d" ,&n , &d1 , &d2))
      {
            for(int i = 1; i <= n; i++)
                  scanf("%d" , &a[i]) ;
            ll ans = 0 ;
            if(d1 == d2)
            {
                  ll sum = 1;
                  for(int i = 2; i <= n; i++)
                        if(a[i] == a[i-1] + d1)
                              sum++ ;
                        else
                        {
                              ans += (sum+1)*sum/2 ;
                              sum = 1 ;
                        }
                  ans += (sum+1)*sum/2 ;
            }
            else
            {
                  l[0] = 0 ; r[n+1] = 0 ;
                  for(int i = 1; i <= n; i++)
                        if(a[i] == a[i-1] + d1)
                              l[i] = l[i-1] + 1 ;
                        else l[i] = 1 ;
                  for(int i = n; i >= 1; i--)
                        if(a[i] == a[i+1] - d2)
                              r[i] = r[i+1] + 1 ;
                        else r[i] = 1 ;
                  for(int i = 1; i <= n; i++)
                        ans += l[i]*r[i] ;
            }
            printf("%lld\n" , ans) ;
      }
      return 0 ;
}
