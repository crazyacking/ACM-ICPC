/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-26-08.00
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
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int a[5],b[5];
      for(int i=0;i<5;++i)
            cin>>a[i];
      for(int i=0;i<5;++i)
            cin>>b[i];
      int ans=0;
      bool flag=true;
      for(int i=0;i<5;++i)
      {
            if(a[i]==b[i])
            {
                  flag=false;
                  break;
            }
      }
      if(!flag) cout<<"N"<<endl;
      else cout<<"Y"<<endl;
      return 0;
}
/*

*/
