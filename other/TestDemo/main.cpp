/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-26-10.27
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
struct node
{
      int x,y;
      bool vis;
      int a;
      node() {vis=false;}
      bool operator<(node a)const
      {
            return x==a.x?y<a.y:x<a.x;
      }
};

set<node> se;

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int a[]={1,4,2,3,4,7,4,8,9};
      sort(a,a+9);
      if(binary_search(a,a+9,11))
      {
            cout<<"YES"<<endl;
      }
      else cout<<"NO"<<endl;
      return 0;
}
/*

*/
