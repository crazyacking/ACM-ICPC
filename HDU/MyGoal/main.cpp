/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-04-13.28
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
const int MAXN=90010;

int l1,l2;
char s1[MAXN],s2[MAXN];
vector<vector<int> > cnt1(130),cnt2(130);
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%s%s",s1,s2);
            l1=strlen(s1),l2=strlen(s2);
            for(int i=0;i<130;++i) cnt1[i].clear(),cnt2[i].clear();
            // cnt
            for(int i=0;i<l1;++i)
            {
                  char ch=s1[i];
                  int num=1;
                  if(s1[i]==s1[i+1])
                  {
                        while(s1[i]==s1[i+1])
                        {
                              ++i;
                              ++num;
                        }
                  }
                  cnt1[ch].push_back(num);
            }

            for(int i=0;i<l2;++i)
            {
                  char ch=s2[i];
                  int num=1;
                  if(s2[i]==s2[i+1])
                  {
                        while(s2[i]==s2[i+1])
                        {
                              ++i;
                              ++num;
                        }
                  }
                  cnt2[ch].push_back(num);
            }

            // test
            for(int i=97;i<123;++i)
            {
                  int si=cnt1[i].size();
                  printf("%c:",i);
                  for(int j=0;j<si;++j)
                  {
                        printf("%d ",cnt1[i][j]);
                  }
                  puts("");

            }
            /********************************************** END ***************************************************/


      }
      return 0;
}
/*

*/
