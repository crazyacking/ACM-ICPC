#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;


typedef vector <int > VI;
#define REP(i,n) for (int i=0; i<n; ++i)
#define FOREACH(it,var) for(__typeof((var).begin()) it=(var.begin()); it!=(var).end(); ++it)
#define FOR(var,pocz,koniec) for (int var=pocz; var<=koniec; ++var)

int t[3000];

class Fuses
{
public:
    int minFuses(vector <int> amps)
    {
        int n=amps.size();
        t[0]=0;
        int ile=1<<n;
        FOR(i,1,ile-1)
        {
            t[i]=10000;
            FOR(j,1,ile-1) if ((i&j)==j)
            {
                int acc=0;
                REP(k,n) if ((1<<k)&j) acc+=amps[k];
                if(acc<=20) t[i]=min(t[i],t[i-j]+1);
            }
        }
        return t[ile-1];
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
        Fuses fuses;
        int ans=fuses.minFuses(nums);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/

