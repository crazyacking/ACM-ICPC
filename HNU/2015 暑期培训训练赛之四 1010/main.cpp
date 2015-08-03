/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-02-20.25
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

map<string,int> mp;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      while(cin>>n)
      {
            string s;
            for(int i=0;i<n;++i)
            {
                  cin>>s;
                  ++mp[s];
            }
            int cnt=0;
            for(int i=0;i<n;++i)
            {
                  cin>>s;
                  if(mp[s]>0)
                  {
                        --mp[s];
                        cnt++;
                  }
            }
            cout<<cnt<<endl;
      }
      return 0;
}
/*

*/
