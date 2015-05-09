
//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-18-21.28
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<climits>
#include<cmath>
#define N 1000010
#define LL long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("C:\\Users\\ASUS\\Desktop\\cin.cpp","r",stdin);
//    freopen("C:\\Users\\ASUS\\Desktop\\cout.cpp","w",stdout);;
    long long a,b;
    while(cin>>a>>b)
    {
            long long  ans=0;
            long long Max,Min;
            while(a!=0 && b!=0)
            {
                    Max=max(a,b);
                    Min=min(a,b);
                    ans+=(Max/Min);
                    Max%=Min;
                    a=Max;
                    b=Min;
            }
            cout<<ans<<endl;
    }
    return 0;
}
/*

*/
