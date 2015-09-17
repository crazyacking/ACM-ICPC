//B 给你n个数字a_n，你可以自行最多k个操作。对于每个操作，你可以对其中一个数字乘以x
//希望a1 | a2 | ... |an尽可能大
//求最大值

// 肯定要把k次操作放在一个地方
//枚举在哪个上面进行k次操作
//然后计算出那个或的值
//计算出n个
//然后找个最大的

#include<bits/stdc++.h>
using namespace std;

typedef long long int64;
const int MAXN=200010;
int64 l[MAXN],r[MAXN];
int64 a[MAXN],t;
int n,k,x;
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      while(~scanf("%d %d %d",&n,&k,&x))
      {
            t=1;
            for(int i=1; i<=k; ++i)
                  t*=x;
            memset(l,0,sizeof l);
            memset(r,0,sizeof r);
            for(int i=1; i<=n; ++i)
            {
                  scanf("%I64d",a+i);
            }
            for(int i=1; i<=n; ++i)
            {
                  l[i]=l[i-1]|a[i];
            }
            for(int i=n; i>=1; --i)
                  r[i]=r[i+1]|a[i];
            int64 res=0;
            for(int i=1; i<=n; ++i)
                  res=max(res,l[i-1]|r[i+1]|(a[i]*t));
            printf("%I64d\n",res);
      }
      return 0;
}
