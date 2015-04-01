//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-31-23.59
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

struct point
{
    double x,y;
};
point A,B,C,D;
int p,q,r;
double length(point X,point Y)
{
    return sqrt((X.x-Y.x)*(X.x-Y.x)+(X.y-Y.y)*(X.y-Y.y));
}
double time(double a,double b)
{
    point X,Y;
    X.x=a*(B.x-A.x)+A.x;
    X.y=a*(B.y-A.y)+A.y;
    Y.x=b*(C.x-D.x)+D.x;
    Y.y=b*(C.y-D.y)+D.y;
    return length(A,X)/p+length(D,Y)/q+length(X,Y)/r;
}
double ThiDiv(double lena)
{
    double left=0.0,right=1.0,lm,rm;
    while(right-left>1e-6)
    {
        lm=(left*2.0+right)/3.0;
        rm=(left+right*2.0)/3.0;
        if(time(lena,lm)<=time(lena,rm))
            right=rm;
        else left=lm;
    }
    return time(lena,left);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y);
        scanf("%lf %lf %lf %lf",&C.x,&C.y,&D.x,&D.y);
        scanf("%d %d %d",&p,&q,&r);
        double left=0.0,right=1.0,lm,rm;
        while(right-left>1e-6)
        {
            lm=(left*2+right)/3.0;
            rm=(left+2*right)/3.0;
            if(ThiDiv(lm)<=ThiDiv(rm))
                right=rm;
            else left=lm;
        }
        printf("%.2f\n",ThiDiv(left));
    }
    return 0;
}
