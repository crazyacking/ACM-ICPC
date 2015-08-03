/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-03-15.54
* Time: 0MS
* Memory: 137KB
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;

LL get(LL n,LL MAX)
{
    vector<LL>q;
    LL ans=0,tt ;
    for(LL i = 2 ; i*i <= n ;i++)
    if(n%i==0)
    {
        while(n%i==0)
        {
            n /= i ;
        }
        q.push_back(i) ;
    }
    // q数组存的是n的所有质因数
    if(n>1)q.push_back(n) ;
    int m = q.size();
    int len=(1<<m) ,e ;
//    cout<<len<<endl;
    for( int i = 1 ; i < len ;i++)
    {
        e=0;
        tt=1;
        for( int j = 0 ; j < m ;j++)
              if((1<<j)&i)
              {
                  tt *= q[j];
                  e++;
              }
        if(e&1) ans += MAX/tt ;
        else ans -= MAX/tt ;
    }
    cout<<ans<<endl;
    return ans;
}

int main()
{
    int i,j,k;
    LL n ,a,ans ;
    while(cin >> a >> n)
    {
        if(a&1)
            ans=(n+1)/2 ,n/=2;
        else ans=0;
        ans += get(a,n) ;
        cout << ans<<endl;
    }
}
