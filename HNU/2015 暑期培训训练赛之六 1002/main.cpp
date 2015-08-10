/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-10-12.47
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
using namespace std;
typedef unsigned long long ULL;
const int MAXN=2010;
const ULL Base1 = 100000007;
const ULL Base2 = 10000007;

int test,hp,wp,hm,wm;
ULL ans;
char G1[MAXN][MAXN],G2[MAXN][MAXN];
ULL hash;
ULL temp[MAXN][MAXN],Temp[MAXN][MAXN];
ULL Gethash()
{
    ULL c,d = 0;
    for(int i = 0; i < hp; ++i) {
        c = 0;
        for(int j = 0; j < wp; ++j)
        {
            c = c*Base1 + G1[i][j];
        }
        d = d * Base2 + c;
    }
    return d;
}

void GetAns() {//把矩阵中的hash算出来，每个子矩阵的。
    ULL t,a;   // 算的时候与目标hash匹配判断一下....
    t = 1;
    for(int i = 0; i < wp; ++i) t *= Base1;
    for(int i = 0; i < hm; ++i) {
        a = 0;
        for(int j = 0; j < wp; ++j) a = a*Base1 + G2[i][j];
        temp[i][wp-1] = a;
        for(int j = wp; j < wm; ++j) {
            temp[i][j]=temp[i][j-1]*Base1-G2[i][j-wp]*t+G2[i][j];
        }
    }

    t = 1;
    for(int i = 0; i < hp; ++i) t *= Base2;
    for(int i = wp-1; i < wm; ++i) {
        a = 0;
        for(int j = 0; j < hp; ++j) a = a*Base2 + temp[j][i];
        Temp[hp-1][i] = a;
        if(a == hash) ans++;
        for(int j = hp; j < hm; ++j) {
            Temp[j][i] = Temp[j-1][i]*Base2 - temp[j-hp][i] * t + temp[j][i];
            if(Temp[j][i]== hash) ans++;
        }
    }
}

int main()
{
    while(scanf("%d%d%d%d",&hp,&wp,&hm,&wm)!= EOF) {
        for(int i = 0; i < hp; ++i) scanf("%s",G1[i]);
        for(int i = 0; i < hm; ++i) scanf("%s",G2[i]);
        hash = Gethash();
        cout<<hash<<endl;
        ans = 0;
        GetAns();
        printf("%llu\n",ans);
    }
    return 0;
}
