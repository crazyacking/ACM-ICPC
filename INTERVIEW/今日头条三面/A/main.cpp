// 给定一个数组array和一个数sum，求array中有多少种两两组合加起来等于sum
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calc(auto nums,int sum)
    {
        unordered_map<int,int> ump;
        for(auto p:nums)
            ++ump[p];
        int res=0;
        for(int i=0;i<nums.size();++i)
        {
            int gap=sum-nums[i];
            if(gap==nums[i])
            {
                if(ump.count(gap)>=2)
                    ++res;
            }
            else
                if(ump.count(gap)>=1)
                    ++res;
        }
        return res>>1;
    }
};

int main()
{
    int n,sum;
    while(cin>>n>>sum)
    {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
            cin>>nums[i];
        Solution solution;
        int ans=solution.calc(nums,sum);
        cout<<ans<<endl;
    }
    return 0;
}
