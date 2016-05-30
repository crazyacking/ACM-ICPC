#include <bits/stdc++.h>
using namespace std;

class TriangleCount {
public:
  int count(int n)
  {
    int i;
    int ret=0;

    for(i=1;i<=n;i++)
      if(i&1) ret+=(i+1)/2*i; else ret+=i/2*(i+1);
    for(i=n-1;i>=1;i-=2)
      if(i&1) ret+=(i+1)/2*i; else ret+=i/2*(i+1);
    return ret;
  }
};

int main()
{
    int len;
    while(cin>>len)
    {
        TriangleCount tc;
        int ans=tc.count(len);
        cout<<ans<<endl;
    }
}
