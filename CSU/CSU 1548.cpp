#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int x,y;
double wid;
int c1,c2;

double cal(double y1)
{
   return sqrt((x-wid)*(x-wid)+y1*y1)*c1
          +sqrt(wid*wid + (y-y1)*(y-y1))*c2;
}
int main()
{
   int n;
   while(~scanf("%d%d%d%d%d",&n,&x,&y,&c1,&c2))
   {
       int a,b;
       wid = 0;
       for(int i = 0;i < n; i ++)
       {
          scanf("%d%d",&a,&b);
          wid += b;
       }
       
       double low = 0;
       double high = y;
       for(int i = 0; i < 100; i ++)
       {
          double le = low + (high-low)/3;
          double ri = low + (high-low)/3 *2;
          
          if(cal(le) < cal(ri))high = ri;
          else low  = le;
       }
       
       printf("%.2f\n",cal(low));
   }
  
}




#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int x,y;
double wid;
int c1,c2;

double cal(double y1)
{
   return sqrt((x-wid)*(x-wid)+y1*y1)*c1
          +sqrt(wid*wid + (y-y1)*(y-y1))*c2;
}
int main()
{
   int n;
   while(~scanf("%d%d%d%d%d",&n,&x,&y,&c1,&c2))
   {
       int a,b;
       wid = 0;
       for(int i = 0;i < n; i ++)
       {
          scanf("%d%d",&a,&b);
          wid += b;
       }
       
       double low = 0;
       double high = y;
       for(int i = 0; i < 100; i ++)
       {
          double le = low + (high-low)/3;
          double ri = low + (high-low)/3 *2;
          
          if(cal(le) < cal(ri))high = ri;
          else low  = le;
       }
       
       printf("%.2f\n",cal(low));
   }
  
}
