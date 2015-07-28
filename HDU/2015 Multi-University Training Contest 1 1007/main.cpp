#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

//用负数方便计算容斥的符号
const int mi[19] = {-2, -3, -5, -7, -11, -13, -17, -19, -23, -29, -31, -37, -41, -43, -47, -53, -59, -61, -67};
long long n;
int r;
vector <int> rongchi; //需要用容斥计算的幂值

void get_rongchi()
{
    rongchi.clear();
    for(int i = 0; abs(mi[i]) <= r; i++)
    {
        int temp = rongchi.size();
        for(int j = 0; j < temp; j++)
        {
            if(abs(mi[i]*rongchi[j]) <= 63)
                rongchi.push_back(mi[i]*rongchi[j]);
        }
        rongchi.push_back(mi[i]);
    }
}

long long cal(long long x) //计算1~x里面实际上在Y数列里的数的个数
{
    if(x == 1)
        return 0;
    long long ans = x;
    for(int i = 0; i < rongchi.size(); i++)
    {
        long long temp = (long long)(pow(x + 0.5, 1.0/abs(rongchi[i]))) - 1; // +0.5为了保证精度，-1是暂时不计算1
        if(rongchi[i] < 0)
            ans -= temp;
        else
            ans += temp;
    }
    return ans - 1; //减去刚才没有计算的1，1是无论如何要被删的
}

void solve()
{
    get_rongchi();
    long long ans = n;
    while(1)
    {
        long long temp = cal(ans);
        if(temp == n)
            break;
        ans += n - temp; //每次加上被删去的数的个数
    }
    printf("%I64d\n", ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%d", &n, &r);
        solve();
    }
    return 0;
}
