#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<vector<string> > VVS;
typedef signed long long i64;
typedef unsigned long long u64;

VI a;
int memo[100][100];
int doit(int s, int e)
{
    if( s == e ) return 0;
    int &ret = memo[s][e];
    if( ret ) return ret;
    ret = 1000000000;
    for( int i = s; i < e; i++ )
        ret =min(ret, doit(s, i) + doit(i+1, e) +
                (a[s]+i-s+1)*a[i+1]*(a[e+1]+e-i));
    return ret;
}

class Assemble
{
public:
    int minCost(vector <int> A)
    {
        memset(memo,0,sizeof memo);
        a = A;
        return doit(0, a.size()-2);
    }
};

int main()
{
//    freopen("G:\\nowcoder\\1.in","r",stdin);
//    freopen("G:\\nowcoder\\1.out","w",stdout);
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
        {
            cin>>nums[i];
        }
        Assemble ass;
        int ans=ass.minCost(nums);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
