/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-24-13.44
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

class node
{
public :
      string name;
      int num,time;
      bool operator < (node a) const
      {
            return num==a.num?time<a.time:num>a.num;
      }
};
node p[120];

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      cin>>t;
      while(t--)
      {
            int n;
            cin>>n;
            for(int i=0;i<n;++i)
            {
                  cin>>p[i].name>>p[i].num>>p[i].time;
            }
            sort(p,p+n);
            cout<<p[0].name<<endl;
      }
      return 0;
}
/*

*/
