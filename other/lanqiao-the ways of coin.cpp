//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-17-19.38
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
#define maxn 1000010
#define LL long long
using namespace std;

double val[4]={100,50,10,5};
int cnt[4];
int ans;

void fun(int x)
{
        double sum=0;
        int ccnt=0;
        for(int i=0;i<4;++i)
        {
                ccnt+=cnt[i];
                sum+=val[i]*cnt[i];
        }
        if(sum==2000 && ccnt==50)
        {
                ans++;
                return;
        }
        else if(sum>2000) return;
        cnt[x]++;
        fun(x);
        cnt[x]--;
        if(x+1<4)
                fun(x+1);
        else return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("C:\\Users\\ASUS\\Desktop\\cin.cpp","r",stdin);
//    freopen("C:\\Users\\ASUS\\Desktop\\cout.cpp","w",stdout);
    memset(cnt,0,sizeof cnt);
    ans=0;
    fun(0);
    cout<<ans<<endl;
    return 0;
}
/*

*/
