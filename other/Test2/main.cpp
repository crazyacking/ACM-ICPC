/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-15-12.56
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

int a[4][3]={{1,2,3,},{4,5,6},{7,8,9},{-1,0,-1}};

set<int> s;

void fun()
{
      int tmp=0;
      for(int i=0;i<4;i++)
      {
            for(int j=0;j<3;++j) // No.1
            {
                  if(a[i][j]!=-1) s.insert(a[i][j]);
                  for(int k=0;k<4;k++)
                  {
                        for(int l=0;l<3;++l) // No.2
                        {
                              if(i<=k && j<=l && a[i][j]!=-1 && a[k][l]!=-1)
                              {
                                    tmp=10*a[i][j]+a[k][l];
                                    if(tmp>=1&&tmp<=200)
                                          s.insert(tmp);
                              }
                              for(int m=0;m<4;++m)
                              {
                                    for(int n=0;n<3;++n) // N0.3
                                    {
                                          if(i<=k && i<=m && k<=m && j<=l && j<=n && l<=n && a[i][j]!=-1 && a[k][l]!=-1&& a[m][n]!=-1)
                                          {
                                                tmp=100*a[i][j] + 10*a[k][l] + a[m][n];
                                                if(tmp>=1 && tmp<=200)
                                                      s.insert(tmp);
                                          }
                                    }
                              }
                        }
                  }
            }
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      fun();
      int si=s.size();
      int t;
      cin>>t;
      while(t--)
      {
            int x;
            cin>>x;
            set<int>::iterator it;
            int ans,gap=INT_MAX;
            for(it=s.begin();it!=s.end();++it)
            {
                  if(abs((*it)-x)<=gap)
                  {
                        gap=abs((*it)-x);
                        ans=(*it);
                  }
            }
            cout<<ans<<endl;

      }
      return 0;
}
/*

*/
