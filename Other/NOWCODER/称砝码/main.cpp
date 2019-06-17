#include <bits/stdc++.h>
using namespace std;

const int MAXN=2050;
int n;
int vals[MAXN],si[MAXN];
void recursive_solve(unordered_set<long long> &us,int cur,long long &sum)
{
    if(cur>=n)
        return;
    for(int i=0; i<=si[cur]; ++i)
    {
        sum+=vals[cur]*i;
        us.insert(sum);
        recursive_solve(us,cur+1,sum);
        sum-=vals[cur]*i;
    }
}


int main()
{
//    freopen("G:\\nowcoder\\1.in","r",stdin);
//    freopen("G:\\nowcoder\\1.out","w",stdout);
    while(cin>>n)
    {
        for(int i=0; i<n; ++i)
            cin>>vals[i];
        for(int i=0; i<n; ++i)
            cin>>si[i];
        unordered_set<long long> us;
        long long sum=0;
        recursive_solve(us,0,sum);
        cout<<us.size()<<endl;
    }
    return 0;
}
/*

*/
