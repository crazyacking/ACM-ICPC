#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string &s)
    {
        int cnt=0;
        int len=s.length();
        for(int i=len-1;i>=0;--i)
        {
            if(s[i]=='-')
            {
                for(int j=i;j>=0;--j)
                {
                    if(s[j]=='+')
                        s[j]='-';
                    else s[j]='+';
                }
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    freopen("C:\\Users\\crazyacking\\Downloads\\B-large.in","r",stdin);
    freopen("C:\\Users\\crazyacking\\Downloads\\out.txt","w",stdout);
    int T;
    cin>>T;
    for(int Cas=1;Cas<=T;++Cas)
    {
        string s;
        cin>>s;
        Solution solution;
        int ans=solution.solve(s);
        cout<<"Case #"<<Cas<<": "<<ans<<endl;
    }
    return 0;
}
