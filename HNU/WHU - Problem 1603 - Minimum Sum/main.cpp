#include <bits/stdc++.h>
using namespace std;
const int N=100010;

int a[N],s[N];
int main()
{
    freopen("G:\\nowcoder\\in","r",stdin);
    freopen("G:\\nowcoder\\out","w",stdout);
    int n,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&k);
        for(int i=0; i<n; ++i)
            scanf("%d",&a[i]);
        sort(a,a+n);
        s[0]=a[0];
        for(int i=1; i<n; ++i)
            s[i]=s[i-1]+a[i];
        long long sum=0,cnt=1-k;
        for(int i=0; i<k; ++i)
        {
            sum+=a[i]*cnt;
            cnt+=2;
        }
        long long res=sum,l=0;
        for(int i=k; i<n; ++i)
        {
            sum-=a[l]*(1-k);
            sum+=a[i]*(k-1);
            sum-=2*(s[i-1]-s[l]);
            res=min(res,sum);
            ++l;
        }
        printf("%lld\n",res);
    }
    return 0;
}
