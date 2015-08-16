#include <iostream>
#include <cstdio>
using namespace std;
double pw;
double vw[100010],pf[100010],vf[100010],th[100010];
const double eps=1e-9;
double cnt(int n,double w)
{
      double ans=n*pw*w;
      for(int i=0;i<n;i++)
      {

            double t=th[i]-w*vw[i];
            if(t<=0)
                  continue;
            ans+=t/vf[i]*pf[i];
      }
      return ans;
}
double work(int n)
{
      double l=0,r=200;
      while(r-l>eps)
      {
            double ll=(2*l+r)/3,rr=(l+2*r)/3;
            if(cnt(n,ll)<cnt(n,rr))
                  r=rr;
            else
                  l=ll;
      }
      return l;
}
int main()
{
      int n;
      while(scanf("%d",&n)!=EOF)
      {
            if(n==0)
                  return 0;
            scanf("%lf",&pw);
            for(int i=0;i<n;i++)
                  scanf("%lf%lf%lf%lf",&vw[i],&pf[i],&vf[i],&th[i]);
            double ans=work(n);
            printf("%.6f\n",cnt(n,ans));
      }
      return 0;
}
