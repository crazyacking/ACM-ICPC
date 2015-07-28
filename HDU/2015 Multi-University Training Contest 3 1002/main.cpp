/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-28-14.01
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

const int NN=10000010;
bool v[NN];
int p[NN];
void makePrime()
{
      int num=-1,i,j;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
      //cout<<num<<endl;
}

int main()
{
//      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
//      freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      makePrime();
      for(int i=0;i<20;++i)
      {
            LL ans=1;
            for(int j=0;j<i;++j)
            {
                  ans*=p[j];
            }
            printf("%d,",ans);
      }
      return 0;
}
/*

*/
