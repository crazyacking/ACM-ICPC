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
            cout<<tmp<<endl;
      }
      return 0;
}
