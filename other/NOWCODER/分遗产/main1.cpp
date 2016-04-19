#include <stdio.h>
long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}
long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main(int argc, char* argv[])
{
    int m,n;
    while (scanf("%d%d", &m, &n) != EOF) {
        if (m == 0 && n == 0) break;
        int a[n];
        int b[n];
        int i;
        int zongshu=1;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            zongshu=lcm(zongshu,a[i]);
        }

        int t,sum,success = 0;
        int yifengpei=0;
        int fac=1;
        while(yifengpei!=m && zongshu<=1400000)
        {
            zongshu*=fac;
            ++fac;
            yifengpei=0;
            for(int i=0;i<n;++i)
            {
                yifengpei+=zongshu/=a[i];
            }
        }
        // for (t = 0; success == 0 && t <= 1400000; t++) {
        //     sum = 0;
        //     m = m + t;
        //     for (i = 0; i < n; i++) {
        //         if (m % a[i] != 0) break;
        //         b[i] = m / a[i];
        //         sum += b[i];
        //     }
        //     m = m - t;
        //     if (i == n && sum == m) success = 1;
        // }
        if (yifengpei==m) {
            printf("%d", b[0]);
            for (i = 1; i < n; i++) {
                printf(" %d", b[i]);
            }
            printf("\n");
        }
        else {
            printf("Can't Solve\n");
        }

    }
    return 0;
}