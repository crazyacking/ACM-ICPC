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


/**< ��ע�Ͱ� */
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
        for(int i=1;i<=n;++i) // ����i��Ϊֹ
        {
            //���ڱ��أ����max_right��ʱ���������ķ�ֵҲ��ͨ��
            int max_right=a[i]/s;
            if(a[i]%s) ++max_right;
            for(int right=0;right<=max_right;++right)  // ö�ٴ�Ե�����
            {
                //���right��ʱ����Ҫ��������
                int dif=a[i]-s*right,fault=0;
                if(dif>0)
                {
                    if(dif%t) fault=dif/t+1;
                    else fault=dif/t;
                }
                fault=max(fault,0);
                for(int chance=m;chance>=right+fault;--chance)
                    dp[i][chance]=min(dp[i][chance],dp[i-1][chance-(right+fault)]+right);
                // dp[i][j] ------������Ϊֹ����ֻ��chance�δ�����ᣬ���ش����right�⣬�������ܹ�ͨ�أ�������Ϊֹ�ܹ�������Ҫ��Զ�����
                // chance-(right+fault) ----- �ܹ��������Ϊchance����������right+fault�Σ�ǰ�����й�ֻ��chance-(right+fault)�λ���
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
