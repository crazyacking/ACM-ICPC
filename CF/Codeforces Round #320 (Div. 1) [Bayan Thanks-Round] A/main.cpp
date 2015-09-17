/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-16-23.09
* Time: 0MS
* Memory: 137KB
*
*/
/*
Mean:
有一个折线穿过(0,0) (x,x) (2x,0) (3x,x) (4x,0) ... (2kx,0) (2kx+x,x) 你知道折线穿过(a,b)，找到最小的x满足它，或者找不到,输出-1

把那个(a,b)沿着图像搞到第一段折线上
先假设答案为x
那么x>=b
然后沿着图像搞到第一段折线上
那么这个时候横纵坐标相等
解个方程
a<b就是-1



找最大的正偶数t使得t<=(a/b)+1
然后ans=(a+b)/t
a/b就是整数运算
ans是实数


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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

long long a,b;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      scanf("%I64d %I64d",&a,&b);
      if(a<b)
      {
            printf("-1\n");
            return 0;
      }
      else
      {
            long long sum=a/b+1;
            long long tmp;
            if(sum%2==0)
            {
                  tmp=sum;
            }
            else
            {
                  tmp=sum-1;
            }
            double ans=(a+b)*1.0/tmp*1.0;
            printf("%.10f\n",ans);

      }
      return 0;
}
/*

*/
