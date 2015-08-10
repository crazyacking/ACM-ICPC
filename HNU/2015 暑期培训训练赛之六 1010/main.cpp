/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-10-08.37
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
const int MAXN=2010;
const ULL seed1 = 10000007;  // line   h
const ULL seed2 = 100000007;// row     w
int hp,wp,hm,wm;
char G1[MAXN][MAXN],G2[MAXN][MAXN];
ULL Tab1[MAXN][MAXN],Tab2[MAXN][MAXN],goal;

void GetHash()
{
      goal=0;
      for(int i=0;i<hp;++i)
      {
            ULL a=0;
            for(int j=0;j<wp;++j)
            {
                  a=a*seed2+G1[i][j];
            }
            goal=goal*seed1+a;
      }
}


int solve()
{
      int ans=0;
      ULL base1=1,base2=1;
      for(int i=0;i<hp;++i) base1*=seed1;
      for(int i=0;i<wp;++i) base2*=seed2;
      for(int i=0;i<hm;++i) // line
      {
            ULL a=0;
            for(int j=0;j<wp;++j) a=a*seed2+G2[i][j];
            Tab1[i][wp-1]=a;
            for(int j=wp;j<wm;++j)
            {
                  Tab1[i][j]=Tab1[i][j-1]*seed2 + G2[i][j] -base2*G2[i][j-wp];
            }
      }
      for(int i=wp-1;i<wm;++i)
      {
            ULL a=0;
            for(int j=0;j<hp;++j) a=a*seed1+Tab1[j][i];
            Tab2[hp-1][i]=a;
            if(a==goal) ++ans;
            for(int j=hp;j<hm;++j)
            {
                  Tab2[j][i]=Tab2[j-1][i]*seed1 +Tab1[j][i] -Tab1[j-hp][i]*base1;
                  if(Tab2[j][i]==goal) ++ans;
            }
      }
      return ans;
}


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d %d %d %d",&hp,&wp,&hm,&wm))
      {
            getchar();
            for(int i=0;i<hp;++i) gets(G1[i]);
            for(int i=0;i<hm;++i) gets(G2[i]);
            GetHash();
            printf("%d\n",solve());
      }
      return 0;
}
/*

*/
