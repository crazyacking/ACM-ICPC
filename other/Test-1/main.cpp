/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-13-21.36
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
#define max(a,b) (a>b?a:b)
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

class BitWise
{
public:
      BitWise(void) {};
      ~BitWise(void) {};
      long long ans;
      void calc(std::string& st,std::string& en)
      {
            if(st>en) swap(st,en);
            int len=st.length();
            for(int i=0; i<len; ++i)
            {
                  st[i]-='a';
                  en[i]-='a';
            }
            std::vector<long long> dp;
            dp.push_back(0);
            dp.push_back(en[0]-st[0]);
            for(int i=1; i<len; ++i)
            {
                  long long tmp=26*(dp[i]+1)-st[i]-1-(26-en[i]);
                  tmp=i==len-1?tmp:tmp+1;
                  dp.push_back(tmp);
            }
            ans=0;
            for(auto ptr:dp) ans+=(ptr);
            ans=max(ans,0);
      }
protected:
private:
};

int main(char args[])
{
      std::ios_base::sync_with_stdio(false);
      std::cin.tie(0);
      std::string s1,s2;
      BitWise bitwise=BitWise();
      while(std::cin>>s1>>s2)
      {
            bitwise.calc(s1,s2);
            std::cout<<bitwise.ans<<std::endl;
      }
      return 0;
}
/*

*/
