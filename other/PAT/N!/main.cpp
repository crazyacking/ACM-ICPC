#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[40000];
    while(cin>>n)
    {
        double digital=0;
        for(int i=1;i<=n;++i)
            digital+=log10(i);
        int m=(int)(digital+1);
        for(int i=0;i<=m;++i)
            a[i]=0;

        a[1]=1;
        int carry=0;
        for(int b=2;b<=n;++b)
        {
            for(int i=1;i<=m;++i)
            {
                a[i]=a[i]*b+carry;
                carry=a[i]/10;
                a[i]%=10;
            }
        }
        printf("%d!=",n);
        for(int i=m;i>=1;--i)
            printf("%d",a[i]);
        printf("\ntotal %d digital.\n",m);
    }
    return 0;
}
