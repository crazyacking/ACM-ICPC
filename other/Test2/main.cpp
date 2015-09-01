/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-31-12.10
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


void scan(int &x)
{
      x=0;
      char c=getchar();
      while(!(c>='0' && c<='9'  || c=='-')) { c=getchar(); }
      bool flag=1;
      if(c=='-')
      {
            flag=0; c=getchar();
      }
      while(c>='0' && c<='9')
      {
            x=x*10+c-'0'; c=getchar();
      }
      if(!flag) { x=-x; }
}
void scan2(int &x,int &y) { scan(x),scan(y);}
void scan3(int &x,int &y,int &z) { scan(x),scan(y),scan(z); }

void print(int x)
{
//      if(x<0) {printf("-"); x=-x;}
      if(x>9) print(x/10);
      putchar(x%10+'0');
}
/**************************************END     define***************************************/
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int a;
      scan(a);
      print(a);
      return 0;
}
/*

*/
