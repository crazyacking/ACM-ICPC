/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-22-22.32
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
      long long a1,a2,a3,a4,a5,a6;
      cin>>a1>>a2>>a3>>a4>>a5>>a6;
      if(a2<a6)
      {
            swap(a2,a6);
            swap(a3,a5);
      }
      long long sum =0;
      sum+=(a1*2-1+2+a1*2 -1+ a6*2) *a6 /2;
      sum+=(a1*2 + a6*2 +a4*2 +a3*2 ) * (a2-a6)/2;
      sum+=(a4*2-1+2+a4*2-1+a3*2)*a3/2;
      cout<<sum<<endl;
      return 0;
}
/*

*/
