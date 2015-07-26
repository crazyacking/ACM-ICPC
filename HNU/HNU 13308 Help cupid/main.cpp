/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-26-08.27
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
int a[50],ti[50];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,tmp;
      while(cin>>n)
      {
            memset(a,0,sizeof a);
            for(int i=0;i<n;++i)
            {
                  cin>>tmp;
                  a[tmp+11]++;
            }
            for(int i=0;i<50;++i) a[i]&=1;
            int cnt=0;
            for(int i=0;i<50;++i)
            {
                  if(a[i]) ti[cnt++]=i;
            }
            int c=cnt;
            for(int i=0;i<c;++i) ti[cnt++]=ti[i]+24;
            LL ans=LLONG_MAX;
            for(int i=0;i<c;++i)
            {
                  LL sum=0;
                  for(int j=0;j<c;j+=2) sum+=ti[i+j+1]-ti[i+j];
                  ans=ans<sum?ans:sum;
            }
            if(ans==LLONG_MAX) cout<<0<<endl;
            else cout<<ans<<endl;
      }
      return 0;
}
/*

*/
