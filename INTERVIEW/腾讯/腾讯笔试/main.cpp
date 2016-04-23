/**<
Mean:
  给定一个字符串s，让你从中删除最少的字符，使得剩下的串是一个回文串.
Analyse:
  仔细想想，发现其实删除和插入都是一个道理（回文的中心对称）.
  方法1：
  设s'为s的最长回文子串(不是最长连续回文子串)，则ans=s.length()-s'.length();
  问题就转化为求s'.length()，可以用最长公共子序列来求，具体方法：
  设rs=reverse(s),则s'.length()就是s和s'的最长公共子序列.
  方法2：
  还是动态规划，假设要求解的问题是p(0,n-1),则：
  if(s[0]==s[n-1])
      p(0,n-1)=p(1,n-2);
  else
      p(0,n-1)=min(p(0,n-2),p(1,n-1))+1;
 */


#include <bits/stdc++.h>
using namespace std;

const static int MAXN=1010;
int dp[MAXN][MAXN];

class Solution
{
public:
    int del_min_char(string &s)
    {
        int n=s.length();
        string rs(n,'0');
        for(int i=0;i<n;++i)
            rs[i]=s[n-1-i];
        int lcs=get_lcs(s,rs);
        return s.length()-lcs;
    }

    int get_lcs(string &s,string &rs)
    {
        int n=s.length();
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=n;++j)
                dp[i][j]=0;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(s[i-1]==rs[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
private:
};

class Solution2
{
public:
    int del_min_char(string &s)
    {
        int n=s.length();
        return solve(s,0,n-1);
    }
    int solve(string &s,int l,int r)
    {
        if(l>=r)
            return s[l]==s[r]?0:1;
        if(s[l]==s[r])
            return solve(s,l+1,r-1);
        else
            return min(solve(s,l+1,r),solve(s,l,r-1))+1;
    }
};

int main()
{
    string s;
    while(cin>>s)
    {
        Solution solution;
        int ans=solution.del_min_char(s);
        cout<<ans<<endl;
    }
    return 0;
}
/**<

test case:

ab -> bab  1
aa -> aa    0
abca -> acbca 1

*/
