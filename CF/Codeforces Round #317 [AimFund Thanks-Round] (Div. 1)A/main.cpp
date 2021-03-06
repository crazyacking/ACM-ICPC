/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-23-12.24
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
using namespace std;
typedef long long LL;

LL cal(LL a,LL b,LL c,LL l)
{
	LL ans=0;
	for(LL i=max(b+c-a,0LL);i<=l;++i)
	{
		LL x=min(l-i,a+i-b-c);
		ans+=(1+x)*(2+x)/2;
	}
	return ans;
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL a,b,c,l;
	cin>>a>>b>>c>>l;
	LL ans=0;
	for(LL i=0;i<=l;++i)
		ans+=LL(1+i)*(2+i)/2;
	ans-=cal(a,b,c,l);
	ans-=cal(b,a,c,l);
	ans-=cal(c,a,b,l);
	cout<<ans;
      return 0;
}
/*

*/
