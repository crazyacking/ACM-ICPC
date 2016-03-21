#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Merge_Sort(vector<int>& nums)
    {
        int len=nums.size();
        vector<int> res;
        if(!len) return res;
        res=Merge(nums,0,len-1);
        return res;
    }

    vector<int> Merge(vector<int>& nums,int l,int r)
    {
        vector<int> res;
        if(l==r)
        {
            res.push_back(nums[l]);
            return res;
        }
        int mid=(l+r)>>1;
        vector<int> part1=Merge(nums,l,mid);
        vector<int> part2=Merge(nums,mid+1,r);
        int i=0,j=0;
        while(i<part1.size() || j<part2.size())
        {
            if(i>=part1.size())
            {
                res.push_back(part2[j++]);
                continue;
            }
            if(j>=part2.size())
            {
                res.push_back(part1[i++]);
                continue;
            }

            if(part1[i]<part2[j])
            {
                res.push_back(part1[i]);
                ++i;
            }
            else
            {
                 res.push_back(part2[j]);
                 ++j;
            }
        }
        return res;
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
        vector<int> ans=solution.Merge_Sort(nums);
        for(auto p:ans)
            cout<<p<<" ";
        cout<<endl;
    }
    return 0;
}
