//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-16-18.01
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
#define LL long long
using namespace std;;

vector<int> L[1000];
int memo[1000];

int solve(int pos){
    int&ret = ;memo[pos];

    if(ret == -1){
        ret = 0;
        bool have[1000];
        memset(have,false,sizeof have);

        for(int i = L[pos].size() - 1;i >= 0;--i)
            have[ solve(L[pos][i]) ] = true;

        while(have[ret]) ++ret;
    }

    return ret;
}

int main(){
    int N,M;

    while(scanf("%d",&N) == 1){
        for(int i = 0;i < N;++i)
            L[i].clear();

        for(int i = 0,sz,x;i < N;++i){
            scanf("%d",&sz);

            for(int j = 0;j < sz;++j){
                scanf("%d",&x);
                L[i].push_back(x);
            }
        }

        memset(memo,-1,sizeof memo);

        while(true){
            scanf("%d",&M);
            if(M == 0) break;

            int ans = 0;

            for(int i = 0,x;i < M;++i){
                scanf("%d",&x);
                ans ^= solve(x);
            }

            puts(ans == 0? "LOSE" : "WIN");
        }
    }

    return 0;
}
