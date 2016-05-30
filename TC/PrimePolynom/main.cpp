#include <bits/stdc++.h>
using namespace std;

class PrimePolynom
{
public:
  bool isprime(int a)
  {
                if (a < 2) return false;
    for (int i = 2; i * i <= a; i++)
    {
      if ((a % i) == 0)
        return false;
    }
    return true;
  }

  int reveal(int A, int B, int C)
  {
    for (int m = 0; true; m++)
    {
      if (!isprime(A*m*m+B*m+C))
        return m;
    }
  }
};

int main()
{
    int n;
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        PrimePolynom pp;
        int ans=pp.reveal(a,b,c);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
