/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-30-21.00
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int N=1010;
LL a[N],dp[N][N];

int main()
{
    int Cas;
    cin>>Cas;
    while(Cas--)
    {
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            fill(dp[i],dp[i]+N,INT_MAX);
        }
        fill(dp[0],dp[0]+N,0);
        for(int i=1;i<=n;++i)
        {
            int max_right=a[i]/s;
            if(a[i]%s) ++max_right;
            for(int right=0;right<=max_right;++right)
            {
                int dif=a[i]-s*right,fault=0;
                if(dif>0)
                {
                    if(dif%t) fault=dif/t+1;
                    else fault=dif/t;
                }
                fault=max(fault,0);
                for(int chance=m;chance>=right+fault;--chance)
                    dp[i][chance]=min(dp[i][chance],dp[i-1][chance-(right+fault)]+right);
            }
        }
        if(dp[n][m]<INT_MAX)
            cout<<dp[n][m]<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
/*

*/


/**< 带注释版 */
/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-30-21.00
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int N=1010;
LL a[N],dp[N][N];

int main()
{
    int Cas;
    cin>>Cas;
    while(Cas--)
    {
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            fill(dp[i],dp[i]+N,INT_MAX);
        }
        fill(dp[0],dp[0]+N,0);
        for(int i=1;i<=n;++i) // 到第i关为止
        {
            //对于本关，答对max_right题时，不算错题的分值也能通关
            int max_right=a[i]/s;
            if(a[i]%s) ++max_right;
            for(int right=0;right<=max_right;++right)  // 枚举答对的题数
            {
                //答对right题时，需要答错多少题
                int dif=a[i]-s*right,fault=0;
                if(dif>0)
                {
                    if(dif%t) fault=dif/t+1;
                    else fault=dif/t;
                }
                fault=max(fault,0);
                for(int chance=m;chance>=right+fault;--chance)
                    dp[i][chance]=min(dp[i][chance],dp[i-1][chance-(right+fault)]+right);
                // dp[i][j] ------到本关为止，若只有chance次答题机会，本关答对了right题，若本关能够通关，到本关为止总共最少需要答对多少题
                // chance-(right+fault) ----- 总共答题机会为chance，本关用了right+fault次，前面所有关只有chance-(right+fault)次机会
            }
        }
        if(dp[n][m]<INT_MAX)
            cout<<dp[n][m]<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
/*

*/
