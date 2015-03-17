//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-17-22.40
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

void bigmul(int x, int y, int r[])
{
    int base = 10000;
    int x2 = x / base;
    int x1 = x % base;
    int y2 = y / base;
    int y1 = y % base;

    int n1 = x1 * y1;
    int n2 = x1 * y2;
    int n3 = x2 * y1;
    int n4 = x2 * y2;

    r[3] = n1 % base;
    r[2] = n1 / base + n2 % base + n3 % base;
    r[1] = n3/base +n2%base + n4%base; // МоїХ
    r[0] = n4 / base;

     r[3]=r[3]%base;  //МоїХ
    r[2] = r[2] % base;
    r[0] += r[1] / base;
    r[1] = r[1] % base;
}
int main(int argc, char* argv[])
{
    int x[] = {0,0,0,0};
    bigmul(99, 99, x);
    printf("%d%d%d%d\n", x[0],x[1],x[2],x[3]);
    system("pause");
    return 0;
}
