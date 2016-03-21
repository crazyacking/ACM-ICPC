#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        permutate(res,nums,0);
        return res;
    }

    void permutate(vector<vector<int>>& res,vector<int> nums,int begin)
    {
        if(begin>=nums.size())
            res.push_back(nums);
        for(int i=begin;i<nums.size();++i)
        {
            if(i!=begin && nums[i]==nums[begin])
                continue;
            swap(nums[i],nums[begin]);
            permutate(res,nums,begin+1);
        }
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
            cin>>nums[i];
        Solution solution;
        auto ans=solution.permuteUnique(nums);
        for(auto p1:ans)
        {
            for(auto p2:p1)
            {
                cout<<p2<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
