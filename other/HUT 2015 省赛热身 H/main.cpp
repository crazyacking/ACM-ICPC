#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
      int n,d;
      while(scanf("%d%d",&n,&d)!=EOF)
      {
            int m=n-2;
            bool flag=0;
            for(int i=1;i<=m;i++)
            {
                  if(flag)
                        putchar(' ');
                  putchar('1');
                  flag=1;
            }
            if(flag)
                  putchar(' ');
            printf("2 %d\n",n+d);
      }
    return 0;
}
