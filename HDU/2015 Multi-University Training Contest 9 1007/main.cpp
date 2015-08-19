/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-18-15.57
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
int n,m;
int a[110][110];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d %d",&n,&m))
      {
            LL sum=0;
            for(int i=0;i<n;++i)
            {
                  for(int j=0;j<m;++j)
                        scanf("%d",&a[i][j]),sum+=a[i][j];
            }
            bool flag=true;
            if(n%2==1||m%2==1)
            {
                  printf("%I64d\n",sum);
                  if(n%2==1)
                  {
                        for(int i=0;i<n-1;++i)
                        {
                              for(int j=0;j<m-1;++j)
                                    printf("%c",flag?'R':'L');
                              printf("%c",'D');
                              flag=!flag;
                        }
                        for(int i=0;i<m-1;++i) printf("%c",flag?'R':'L');
                        puts("");
                        continue;
                  }

                  if(m%2==1)
                  {
                        for(int i=0;i<m-1;++i)
                        {
                              for(int j=0;j<n-1;++j)
                                    printf("%c",flag?'D':'U');
                              printf("%c",'R');
                              flag=!flag;
                        }
                  }
                  for(int i=0;i<n-1;++i) printf("%c",flag?'D':'U');
                  puts("");
                  continue;
            }
            // structure
            int mi=INT_MAX,row,col;
            for(int i=0;i<n;++i)
            {
                  for(int j=0;j<m;++j)
                  {
                        if(((i+j)%2==1) && a[i][j]<mi)
                              mi=a[i][j],row=i,col=j;
                  }
            }
            printf("%I64d\n",sum-mi);
            flag=true;
            for(int i=0;i<n;++i)
            {
                  if(i<=row-2)
                  {
                        for(int j=0;j<m-1;++j)
                              printf("%c",flag?'R':'L');
                        printf("%c",'D'),flag=!flag;
                  }
                  else break;
            }
            bool ff=true;
            if(flag)
            {
                  for(int j=0;j<m-1;++j)
                  {
                        if(j!=col)
                        {
                              printf("%c",ff?'D':'U'),ff=!ff;
                        }
                        printf("%c",flag?'R':'L');
                  }
            }
            else
            {
                  for(int j=m-1;j>0;--j)
                  {
                        if(j!=col)
                              printf("%c",ff?'D':'U'),ff=!ff;
                        printf("%c",flag?'R':'L');
                  }
            }
            flag=!flag;
            if(ff) printf("%c",'D');
            for(int i=(row==0)?row+2:row+1;i<n;++i)
            {
                  printf("D");
                  for(int j=0;j<m-1;++j)
                        printf("%c",flag?'R':'L');
                  flag=!flag;
            }
            puts("");
      }
      return 0;
}
/*

*/
