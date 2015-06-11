//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-17-10.20
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
using namespace std;

long long memo[9][221][221];

long long solve(int n, int m, int last){
    if(n==0){
        if(m>=last) return 1;
        return 0;
    }

    long long &ret = memo[n][m][last];;

    if(ret == -1){
        ret = 0;

        for(int i = last;(n+1) * i <= m;++i)
            ret += solve(n-1,m-i,i);
    }

    return ret;
}

int main(){
    int T,M,N,K;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d %d",&M,&N,&K);

        memset(memo,-1,sizeof(memo));

        int last = 1;

        for(int i = N-1;i>0;--i){
            int tmp = 0,j = last;

            while(true){
                if(tmp + solve(i-1,M-j,j) >= K){
                    printf("%d ",j);
                    K -= tmp;
                    last = j;
                    M -= j;
                    break;
                }

                tmp += solve(i-1,M-j,j);
                ++j;
            }
        }

        printf("%d\n",M);
    }

    return 0;
}
