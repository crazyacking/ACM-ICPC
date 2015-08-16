/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-16-14.49
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


char res[40];

void init()
{
      int i;
      for(i=0;i<=9;++i)
      {
            res[i]=i+'0';
      }
      for(i=10;i<36;++i)
      {
            res[i]='A'+i-10;
      }
      res[36]='\0';
      puts(res);

}
int main()
{
      init();
      ios_base::sync_with_stdio(false);
      cin.tie(0);

      return 0;
}
/*

*/
