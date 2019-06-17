#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double pi=acos(-1.0);
double a,b;
double f(double x)
{
      return pow(a*exp(-x*x)+b*sqrt(x),2);
}
double simpson(double a,double b)
{
      double c=a+(b-a)/2;
      return (f(a)+4*f(c)+f(b))*(b-a)/6;
}
double asr(double a,double b,double eps,double A)
{
      double c=a+(b-a)/2;
      double l=simpson(a,c),r=simpson(c,b);
      if(fabs(l+r-A)<=15*eps)return l+r+(l+r-A)/15;
      return asr(a,c,eps/2,l)+asr(c,b,eps/2,r);
}
double asr(double a,double b,double eps)
{
      return asr(a,b,eps,simpson(a,b));
}
int main()
{
      double v;
      int n;
      while(scanf("%lf%d",&v,&n)!=EOF)
      {
            double ans=1e99;
            int index;
            for(int i=0;i<n;i++)
            {
                  double h;
                  scanf("%lf%lf%lf",&a,&b,&h);
                  double s=pi*asr(0,h,1e-5);
                  //cout<<s<<endl;
                  if(fabs(s-v)<ans)
                  {
                        ans=fabs(s-v);
                        index=i;
                  }
            }
            printf("%d\n",index);
      }
    return 0;
}
