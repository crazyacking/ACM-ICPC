#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums)
{
    int n=nums.size(),dp[n+1]={0};
    dp[0]=1;
    for(int i=1;i<n;++i)
    {
        int maxdp=0;
        for(int j=0;j<i;++j)
        {
            if(nums[j]<=nums[i] && dp[j]>dp[i])
                maxdp=dp[j];
        }
        dp[i]=maxdp+1;
    }
    return dp[n-1];
}

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
            cin>>nums[i];
        int ans=solve(nums);
        cout<<ans<<endl;
    }
    return 0;
}
