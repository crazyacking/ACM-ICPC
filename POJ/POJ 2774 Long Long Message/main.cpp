// Memory   Time
// 1347K     0MS
// by : Snarl_jsb
// 2014-09-24-19.57
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<climits>
#include<cmath>
#define N 1100<<1
#define LL long long
using namespace std;
int num[N];
char s[N],str[N];
namespace Suf
{
int sa[N], rank[N], height[N];
int wa[N], wb[N], wv[N], wd[N];
int cmp( int *r, int a, int b, int l )
{
      return r[a] == r[b] && r[a + l] == r[b + l];
}
void da( int *r, int n, int m )   //    参数:*r---str转化为int型后的数组  n----数组长度  m---元素的范围
{
      int i, j, p, *x = wa, *y = wb, *t;
      for( i = 0; i < m; i ++ ) wd[i] = 0;
      for( i = 0; i < n; i ++ ) wd[x[i] = r[i]] ++;
      for( i = 1; i < m; i ++ ) wd[i] += wd[i - 1];
      for( i = n - 1; i >= 0; i -- ) sa[-- wd[x[i]]] = i;
      for( j = 1, p = 1; p < n; j *= 2, m = p )
      {
            for( p = 0, i = n - j; i < n; i ++ ) y[p ++] = i;
            for( i = 0; i < n; i ++ ) if( sa[i] >= j ) y[p ++] = sa[i] - j;
            for( i = 0; i < n; i ++ ) wv[i] = x[y[i]];
            for( i = 0; i < m; i ++ ) wd[i] = 0;
            for( i = 0; i < n; i ++ ) wd[wv[i]] ++;
            for( i = 1; i < m; i ++ ) wd[i] += wd[i - 1];
            for( i = n - 1; i >= 0; i -- ) sa[-- wd[wv[i]]] = y[i];
            for( t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++ )
                  x[sa[i]] = cmp( y, sa[i - 1], sa[i], j ) ? p - 1 : p ++;
      }
}
void calcHeight( int *r, int n )       //  求height数组
{
      int i, j, k = 0;
      for( i = 1; i <= n; i ++ ) rank[sa[i]] = i;
      for( i = 0; i < n; height[rank[i ++]] = k )
      {
            for( k ? k -- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k ++ );
      }
}
}
using namespace Suf;
//
//int main()
//{
//      ios_base::sync_with_stdio( false );
//      cin.tie( 0 );
//      gets( str );
//      int len1 = strlen( str );
//      for( int i = 0; i < len1; ++i )
//            num[i] = str[i] - 'a' + 2;
//      num[len1] = 1;
//      gets( str );
//      int len2 = strlen( str );
//      for( int i = 0; i < len2; ++i )
//            num[i + len1 + 1] = str[i] - 'a' + 2;
//      int n = len1 + len2;
//
//      da( num, n + 1, 30 );
//      calcHeight( num, n );
//      int ans = 0;
//      for( int i = 2; i < n; ++i )
//      {
//            if( ( sa[i] < len1 && sa[i - 1] > len1 ) || ( sa[i - 1] < len1 && sa[i] > len1 ) ) //判断是否属于不同串
//                  ans = max( ans, height[i] );
//      }
//      cout << ans << endl;
//      return 0;
//}
//


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s",s))
      {
            int len=strlen(s);
            int cnt=0;
            for(int i=len-1;i>=0;--i)
                  str[cnt++]=s[i];
            str[cnt]='\0';
            puts(s);
            puts(str);
            s[len]='a'-1;
            strcat(s,str);
            puts(s);
            int n=strlen(s);
            for(int i=0;i<n;++i)
            {
                  num[i]=s[i];
            }
            n--;
            da(sa,n+1,250);
            calcHeight(num,n);
            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");
            int start = 0;
            int maxx=0;
            for(int i=2;i<n;++i)
            {
                  if((sa[i]<len && sa[i-1]>len) || (sa[i]>len &&sa[i-1]<len))
                  {
                        start=min(sa[i],sa[i-1]);
                        maxx=max(maxx,height[i]);
                  }
            }
            for(int i=start ;i<start + maxx ; ++i)
            {
                  printf("%c",s[i]);
            }
            puts("");
      }
      return 0;
}
/*

*/
