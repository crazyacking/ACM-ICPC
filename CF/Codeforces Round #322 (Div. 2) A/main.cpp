#include<bits/stdc++.h>
using namespace std;
int main()
{
      int a,b;
      cin>>a>>b;
      int ans1=min(a,b);
      int big=max(a,b);
      int ans2=(big-ans1)/2;
      cout<<ans1<<" "<<ans2<<endl;
      return 0;
}
