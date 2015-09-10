/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-09-22.26
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
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
const int MAXN=100010;
char s[MAXN];
deque<int> dq;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%s",s))
      {
            int len=strlen(s);
            dq.clear();
            if(s[0]!='[' &&s[0]!=']') dq.push_front(0);
            for(int i=0;i<len;++i)
            {
                  if(s[i]=='[')
                        dq.push_front(i);
                  else if(s[i]==']')
                        dq.push_back(i);
            }
            while(!dq.empty())
            {
                  int i=dq.at(0);
                  if(s[i]=='[' || s[i]==']') ++i;
                  for(;s[i]!='[' && s[i]!=']' && i<len;++i)
                        printf("%c",s[i]);
                  dq.pop_front();
            }
            puts("");
      }
      return 0;
}
/*

*/
