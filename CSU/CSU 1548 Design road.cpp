//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-30-21.24
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
using name,sum,xx;
double calc(double mid)
{
        double road_cost=sqrt(xx*xx+mid*mid)*c1, bridge_cost=sqrjst(sum*sum+(y-mid)*(y-mid))*c2;
        return road_cost+bridge_cost;
}

double solve(double low,double high)
{
        double l=low,h=high;
        double mid=(l+h)/2,mmid=(mid+h)/2;
        double cmid=calc(mid),cmmid=calc(mmid);
        while(fabs(cmmid-cmid)>=1e-10)
        {
                if(cmid>cmmid)
                        l=mid;
                else
                        h=mmid;
                mid=(l+h)/2,mmid=(mid+h)/2;
                cmid=calc(mid),cmmid=calc(mmid);
        }
        return min(cmmid,cmid);
}

int main()
{
        int n;
        while(cin>>n>>x>>y>>c1>>c2)
        {
                sum=0.0;
                double tmp1,tmp2;
                for(int i=1;i<=n;++i)
                {
                        cin>>tmp1>>tmp2;
                        sum+=tmp2;
                }
                xx=x-sum;
                printf("%.2lf\n",solve(0.0,y));
        }
        return 0;
}
