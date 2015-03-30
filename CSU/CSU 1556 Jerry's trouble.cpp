//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-29-19.18
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define MAXN 1000010
#define LL long long
using namespace std;
const LL MOD=1e9+7;

LL quick_pow(LL a,LL b,LL m)
{
        LL ans=1;
        while(b)
        {
                if(b&1)
                {
                        ans*=a;
                        ans%=m;
                }
                a*=a;
                a%=m;
                b/=2;
        }
        return ans%m;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
//      freopen("C:\\Users\\Devin\\Desktop\\cin.cpp","r",stdin);
//      freopen("C:\\Users\\Devin\\Desktop\\cout.cpp","w",stdout);
        LL n,m;
        while(cin>>n>>m)
        {
                LL sum=0;
                for(int i=1;i<=n;++i)
                {
                        sum+=quick_pow(i,m,MOD);
                        sum%=MOD;
                }
                cout<<sum%MOD<<endl;
        }
        return 0;
}
/*

*/

/**************************************************************
    Problem: 1556
    User: crazyacking
    Language: C++
    Result: Accepted
    Time:2704 ms
    Memory:1476 kb
****************************************************************/
