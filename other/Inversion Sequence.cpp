//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-29-23.24
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
const int maxn = 11111;
int a[maxn];
int ans[maxn];
vector<int>v;

int main(){
//    freopen("data.in","r",stdin);;
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        v.clear();
        v.push_back(0);
        int ok=1;
        for(int i=n-1;i>=0;i--)
        {
            if(v.size()<=a[i])
            {
                ok=0;
                break;
            }
            v.insert(v.begin()+1+a[i],i+1);
//            for(int j=0;j<v.size();j++)
//                printf("%d%c",v[j],j==v.size()-1?'\n':' ');
        }
        if(ok){
            for(int i=1;i<=n;i++){
                printf("%d%c",v[i],i==n?'\n':' ');
            }
        }else{
            puts("No solution");
        }
    }
    return 0;
}

/**************************************************************
    Problem: 1555
    User: crazyacking
    Language: C++
    Result: Accepted
    Time:164 ms
    Memory:1576 kb
****************************************************************/
