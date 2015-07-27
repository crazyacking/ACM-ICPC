/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-27-09.12
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
int a,b;
LL sq[3163000],tri[100010];
void make_table()
{
      int cnt=0;
      for(int i=0;i*i<1000000010*1000000010;++i)
      {
            sq[cnt++]=i*i;
      }
      tri[0]=1;
      LL sum=0;
      int i;
      for(i=1;i<100000;++i)
      {
            tri[i]=tri[i-1]+i+1;
            sum+=tri[i];
      }
}

int main()
{
      make_table();
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int cas=1;
      while(~scanf("%d %d",&a,&b)  && !(a==0 && b==0))
      {
            printf("Case %d: ",cas++);
            if(a>b) swap(a,b);
            int x;
            int ans=0;
            for(int i=0;i<36518;++i)
            {
                  if(sq[i]>a&&sq[i]<b&&binary_search(tri,tri+100000,sq[i]-1))
                  {
                              ans++;
                  }
            }
            printf("%d\n",ans);
      }
      return 0;
}
/*

*/
