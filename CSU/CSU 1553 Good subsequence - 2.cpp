//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-30-16.02
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
int n,k;
vector<int> ve;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
//      freopen("C:\\Users\\Devin\\Desktop\\cin.cpp","r",stdin);
//      freopen("C:\\Users\\Devin\\Desktop\\cout.cpp","w",stdout);
        while(cin>>n>>k)
        {
                ve.clear();
                for(int i=0;i<n;++i)
                {
                        int tmp;
                        cin>>tmp;
                        ve.push_back(tmp);
                }
                int ans=1;
                for(int i=0;i<n;++i)
                {

                        int cnt=1;
                        int maxx=ve[i];
                        int minn=ve[i];
                        for(int j=i+1;j<n;++j)
                        {
                                if(ve[j]>=maxx)
                                {
                                        maxx=ve[j];
                                }
                                if(ve[j]<=minn)
                                {
                                        minn=ve[j];
                                }
                                if(maxx-minn>k) break;
                                cnt++;
                        }
                        if(cnt>ans) ans=cnt;
                }
                cout<<ans<<endl;
        }
        return 0;
}
/*

*/
