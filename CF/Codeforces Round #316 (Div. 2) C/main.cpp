/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-14-01.18
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
#define  LL __int64
#define  ULL unsigned long long
using namespace std;

char c[300005],d[15];
int main()
{
      LL n,m,i,answer=0;
      scanf("%I64d %I64d",&n,&m);
      scanf("%s",c);
      for(i=1; c[i]!='\0'; i++)
      {
            if(c[i]!='.') continue;
            else if(c[i-1]=='.') answer++;
      }
      for(i=0; i<m; i++)
      {
            LL fau;
            scanf("%I64d%s",&fau,d); fau--;
            if((d[0]=='.')&&(c[fau]=='.'))
            {
                  printf("%I64d\n",answer);
                  continue;
            }
            if((d[0]!='.')&&(c[fau]!='.'))
            {
                  printf("%d\n",answer); continue;
            }
            if(d[0]!='.')
            {
                  if((fau!=0)&&(c[fau-1]=='.')) answer--;
                  if((fau!=n-1)&&(c[fau+1]=='.')) answer--;
            }
            else
            {
                  if((fau!=0)&&(c[fau-1]=='.')) answer++;
                  if((fau!=n-1)&&(c[fau+1]=='.')) answer++;
            }
            c[fau]=d[0];
            printf("%d\n",answer);
      }
      return 0;
}
