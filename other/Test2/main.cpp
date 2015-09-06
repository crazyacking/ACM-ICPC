#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
      int t,n;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d",&n);
            double tmp=log10(double(n));
            double res=tmp-floor(tmp);
            cout<<res<<endl;
            printf("%d\n",(int)pow(10.0,res));
      }
      return 0;
}
