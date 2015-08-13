/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-11-22.57
* Time: 0MS
* Memory: 137KB
*/
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-12-16.40
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
const int MAXN=100010;
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
/**************************************END     define***************************************/
/** O(n)内求出所有回文串
 *原串 :abaaba
 *Ma串 :.,a,b,a,a,b,a,
 *Mp[i]:Ma串中，以字符Ma[i]为中心的最长回文子串的半径长度(包括Ma[i],也就是把回文串对折后的长度).
 ****经过对原串扩展处理后，将奇数串的情况也合并到了偶数的情况(不需要考虑奇数串)
 */
int s[MAXN],Ma[MAXN<<1],Mp[MAXN<<1],Mplen,n;
void Manacher(int len)
{
      int le=0;
      Mp[le]=0;
      Ma[le++]=-2;
      Mp[le]=1;
      Ma[le++]=-1;
      for(int i=0;i<len;++i)
      {
            scan(s[i]);
            Ma[le++]=s[i];
            Ma[le++]=-1;
      }
      Mplen=le;
      Ma[le]=0;
      int pnow=0,pid=0;
      for(int i=1;i<le;++i)
      {
            if(pnow>i)
                  Mp[i]=Mp[2*pid-i]<pnow-i?Mp[2*pid-i]:pnow-i;
            else
                  Mp[i]=1;
            for(;Ma[i-Mp[i]]==Ma[i+Mp[i]];++Mp[i]);
            if(i+Mp[i]>pnow)
            {
                  pnow=i+Mp[i];
                  pid=i;
            }
      }
}

int main()
{
      int t;
      scanf("%d",&t);
      for(int Cas=1;Cas<=t;++Cas)
      {
            scanf("%d",&n);
            Manacher(n);
            int ans=0,rad;
            for(int i=3;i<Mplen-3;i+=2)
            {
                  rad=--Mp[i];
                  if(rad>ans && rad>1)
                  {
                        while(Mp[i+rad]<=rad && rad>ans) --rad;
                        ans=ans>rad?ans:rad;
                  }
            }
            printf("Case #%d: %d\n",Cas,ans/2*3);
      }
      return 0;
}
