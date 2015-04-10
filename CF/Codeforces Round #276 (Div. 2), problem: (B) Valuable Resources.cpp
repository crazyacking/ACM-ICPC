#include <iostream>
#include <cstdio>
#include <cstdlib>


using namespace std;

int main()
{
    int n;
    long long x, y;
    long long minx = 1e9 + 9, maxx = -1 * (1e9 + 9), maxy = -1 * (1e9 + 9), miny = 1e9 + 9;
    
    ios_base::sync_with_stdio(0);
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
      {
          cin>>x>>y;
          
          if(x > maxx)
            maxx = x;
          
          if(minx > x)
            minx = x;
          
          if(maxy < y)
            maxy = y;
          
          if(miny > y)
            miny = y;
      }
    
    x = max(maxy - miny, maxx - minx);
    
    cout<<x * x<<endl;
    

    return 0;
}
