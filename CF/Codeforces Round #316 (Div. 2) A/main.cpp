/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-14-01.08
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

int numberSum[105];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<m;i++)
    {
        int j;
        int k=-1,ma=-1;
        for (j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            if (x>ma)
            {
                k=j,ma=x;
            }
        }
        numberSum[k]++;
    }
    int k=-1,ma=-1;
    for (i=0;i<n;i++)
    {
        if (numberSum[i]>ma)
        {
            ma=numberSum[i];
            k=i;
        }
    }
    printf("%d\n",k+1);
    return 0;
}
