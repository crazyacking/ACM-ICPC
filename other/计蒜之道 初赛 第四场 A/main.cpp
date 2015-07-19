/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-18-23.20
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
#define MOD 1000000007
using namespace std;


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL a[]={5, 54, 550, 5700, 58830,607752};
      int t;
      cin>>t;
      while(t--)
      {
            int n;
            cin>>n;
            cout<<a[n-1]%MOD<<endl;
      }
      return 0;
}
/*

*/

