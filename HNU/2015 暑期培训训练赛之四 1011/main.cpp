/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-03-11.45
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
const int N=2005;
int n,s,t,a[N];
LL dp[N];
multiset<int> st;
vector<pair<int,LL> >vt;
long long gcd(long long a,long long b)
{
      return !b?a:gcd(b,a%b);
}
void solve()
{
      for(int i=0;i<n;++i)
      {
            st.clear();
            for(int j=0;j<n;++j)
            {
                  if(i!=j)
                        st.insert(a[j]);
            }
            int cur=a[i],step=n-1;
            LL res=0;
            while(step--)
            {
                  int nxt=(cur+t)%s;
                  res+=t;
                  multiset<int>::iterator tmp=st.lower_bound(nxt);
                  if(tmp!=st.end())
                  {
                        res+=*tmp-nxt;
                        cur=*tmp;
                        st.erase(tmp);
                  } else {
                        res+=s-nxt;
                        tmp=st.lower_bound(0);
                        res+=*tmp;
                        cur=*tmp;
                        st.erase(tmp);
                  }
            }
            dp[i]=res+t;
      }
      LL mx=dp[0],mn=dp[0];
      for(int i=1;i<n;++i)
      {
            mx=max(mx,dp[i]);
            mn=min(mn,dp[i]);
      }
      vt.clear();
      for(int i=0;i<n;++i)
            vt.push_back(make_pair(a[i],dp[i]));
      sort(vt.begin(),vt.end());
      vt.push_back(make_pair(vt[0].first+s,vt[0].second));
      LL sum=0;
      for(int i=1;i<vt.size();++i)
            if(vt[i].first!=vt[i-1].first){
                  int len=vt[i].first-vt[i-1].first;
                  sum+=vt[i].second*len + 1LL*(len-1)*len/2;
                  mx=max(mx,vt[i].second+len-1);
            }
            LL sum2=s;
            LL d=gcd(sum,sum2);
            sum/=d; sum2/=d;
            printf("%lld\n%lld\n",mn,mx);
            printf("%lld\n%lld\n",sum,sum2);
}

int main()
{
      ios_base::sync_with_stdio(false);
      sync_with
      cin.tie(0);
      while(~scanf("%d %d %d",&n,&s,&t))
      {
            for(int i=0;i<n;++i)
                  scanf("%d",&a[i]);
      }

      solve();
      return 0;
}
/*

*/
