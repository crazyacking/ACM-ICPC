/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-06-02.19
* Time: 0MS
* Memory: 137KB
*/
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define  LL long long
#define  ULL unsigned long long
using namespace std;

int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      int n,k;
      while(~scanf("%d %d",&n,&k))
      {
            map<int,int> l,r;
            long long ans=0;
            vector<int> input;
            for(int i=0;i<n;++i)
            {
                  int x;
                  scanf("%d",&x);
                  input.push_back(x);
                  ++r[x];
            }
            for(int i=0;i<n;++i)
            {
                  --r[input[i]];
                  if(input[i]%k==0)
                  {
                        long long ll=((long long) input[i])/k;
                        long long rr=((long long) input[i])*k;
                        long long cl=l[ll];
                        long long cr=r[rr];
                        ans+=cl*cr;
                  }
                  ++l[input[i]];
            }
      cout<<ans<<endl;
      }

      return 0;
}
/*

*/
