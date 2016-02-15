#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans=0;
        int len=s.length();
        int currentLength=0;
        int recentCycleIndex=0;
        map<char,int> mp;
        for(int i=0; i<len; ++i)
        {
            if(mp.find(s[i])==mp.end())
                currentLength++;
            else
            {
                if(mp[s[i]]<=recentCycleIndex)
                    currentLength=i-recentCycleIndex;
                else
                    currentLength=i-mp[s[i]];
                recentCycleIndex=max(recentCycleIndex,mp[s[i]]);
            }
            mp[s[i]]=i;
            ans=max(ans,currentLength);
        }
        return ans;
    }
};

int main()
{
    string s;
    while(cin>>s)
    {
        Solution solution;
        int answer=solution.lengthOfLongestSubstring(s);
        cout<<"============answer============="<<endl;
        cout<<answer<<endl;
    }
    return 0;
}
