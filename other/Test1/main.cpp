
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-11-01.30
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



bool ispalin(int x)
{
      char s[100];
      sprintf(s,"%d",x);
      int len=strlen(s);
      bool flag=true;
      for(int i=0;i<len/2;++i)
      {
            if(!(s[i]==s[len-i-1]))
            {
                  flag=false;
                  break;
            }
      }
      return flag;

}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      while(cin>>n)
      {
            if(ispalin(n))
            {
                  puts("yes");
            }
            else
            {
                  puts("no");
            }
      }
      return 0;
}
/*

*/
