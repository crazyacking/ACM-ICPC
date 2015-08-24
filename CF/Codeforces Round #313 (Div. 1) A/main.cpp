#include<cstdio>
using namespace std;

double Pow(double a,int b)
{
      double ans=1.0;
      while(b)
      {
            if(b&1) { ans=(ans*a),b--; }
            b/=2,a=a*a;
      }
      return ans;
}

int main()
{
      int n,m;
      while(scanf("%d %d",&n,&m)!=EOF)
      {
            double t1=(1.-Pow((n-1)*1./n,m))*n;
            printf("%.3f\n",t1);
      }
      return 0;
}
