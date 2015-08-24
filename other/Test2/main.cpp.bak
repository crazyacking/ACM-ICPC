/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-23-23.27
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

const int MAXN=40005;
int fac[40],numfac[40];
bool v[MAXN];
int p[MAXN];
void makePrime()
{
      int num=-1,i,j;
      for(i=2; i<MAXN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<MAXN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
}


LL divFac(LL n)//分解因数
{
	LL i,num=0;
	for(i=0;p[i]*p[i]<=n;i++)
	{
		if(n%p[i]==0)
		{
			fac[num]=p[i];
			numfac[num]++;
			n=n/p[i];
			while(n%p[i]==0)
			{
				numfac[num]++;
				n=n/p[i];
			}
			num++;
		}
		if(n==1)
			break;
	}
	if(n>1)
	{
		fac[num]=n;
		numfac[num]++;
		num++;
	}
	return num;
}

int main()
{
      makePrime();
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      while(cin>>n)
      {
            int si=divFac(n);
            for(int i=0;i<si;++i)
            {
                  printf("%d ",fac[i]);
            }
      }
      return 0;
}
/*

*/
