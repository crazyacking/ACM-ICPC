#include <bits/stdc++.h>
using namespace std;

// way 1: use system's function:next_permutation(iter* begin,iter* end);
//class Solution
//{
//public:
//    vector<vector<int>> permute(vector<int>& nums)
//    {
//        vector<vector<int>> res;
//        sort(nums.begin(),nums.end());
//        res.push_back(nums);
//        while(next_permutation(nums.begin(),nums.end()))
//            res.push_back(nums);
//        return res;
//    }
//};

class Solution
{
public:
    vector<vector<int>> permute(vector<int>nums)
    {
        vector<vector<int>> res;
//        sort(nums.begin(),nums.end());
        solvePermute(res,nums,0);
        return res;
    }

    void solvePermute(vector<vector<int>>& res,vector<int> nums,int begin)
    {
        if(begin>=nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=begin; i<nums.size(); ++i)
        {
            swap(nums[i],nums[begin]);
            solvePermute(res,nums,begin+1);
            swap(nums[i],nums[begin]);
        }
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> ve(n);
        for(int i=0; i<n; ++i)
            cin>>ve[i];
        Solution solution;
        vector<vector<int>> ans=solution.permute(ve);
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
