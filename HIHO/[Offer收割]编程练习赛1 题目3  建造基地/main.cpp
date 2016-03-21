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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int NN = 1e2 + 10;
using namespace std;
LL dy[10010];
unsigned a[NN],b[NN];

int N,M,K,T,Q;
LL WORK()
{
    unsigned cnts = 0;
    for(int i = 0; i < M; ++i) cnts = max(cnts,b[i]);
    if(!cnts) return -1;

    for(int i = 1; i <= K; ++i) dy[i] = 1e18;
    dy[0] = 0;
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j <= K; ++j)
        {
            int x = min(K+0LL,j+b[i]+0LL);
            dy[x] = min(dy[x],dy[j]+a[i]);
        }
    }
    return dy[K];
}

int main()
{
    scanf("%d",&Q);
    for(int cas = 1; cas <= Q; ++cas)
    {
        scanf("%d %d %d %d",&N,&M,&K,&T);
        for(int i = 0; i < M; ++i) scanf("%u",a+i);
        for(int i = 0; i < M; ++i) scanf("%u",b+i);
        LL cost = 0;
        for(int i = 0; i < N; ++i)
        {
            if(WORK() < 0)
            {
                cost = -1;
                break;
            }
            cost += WORK();
            for(int j = 0; j < M; ++j) b[j] /= T;
        }
        if(cost == -1) puts("No Answer");
        else printf("%lld\n",cost);
    }
    return 0;
}
