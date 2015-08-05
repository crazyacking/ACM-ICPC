/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-04-21.30
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
/**< force check */
vector<string> ve;
int main()
{
//      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      string s1=string("b");
      string s2=string("a");
      ve.push_back(s1),ve.push_back(s2);
      string tmp;
      for(int i=0;i<=11;++i)
      {
            tmp=s2;
            s2=s2+s1;
            s1=tmp;
            ve.push_back(s2);
      }
      for(int i=0;i<=11;++i)
      {
            cout<<ve[i]<<endl;
      }
      return 0;
}
/*

*/
