#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
      vector<int> ve={5,6,4,8,4,0,4,5,8,1,545};
      sort(ve.begin(),ve.end());

      int si=ve.size();
      cout<<si<<endl;
      return 0;
}
