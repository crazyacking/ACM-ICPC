/**<
Mean:
  ����һ���ַ���s���������ɾ�����ٵ��ַ���ʹ��ʣ�µĴ���һ�����Ĵ�.
Analyse:
  ��ϸ���룬������ʵɾ���Ͳ��붼��һ���������ĵ����ĶԳƣ�.
  ����1��
  ��s'Ϊs��������Ӵ�(��������������Ӵ�)����ans=s.length()-s'.length();
  �����ת��Ϊ��s'.length()����������������������󣬾��巽����
  ��rs=reverse(s),��s'.length()����s��s'�������������.
  ����2��
  ���Ƕ�̬�滮������Ҫ����������p(0,n-1),��
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
