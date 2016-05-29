#include <bits/stdc++.h>
using namespace std;

void full_permutation(vector<int>& nums,int cur,int end)
{
    if(cur==end)
    {
        for(auto p:nums)
            cout<<p<<" ";
        cout<<endl;
        return ;
    }
    else
    {
        for(int i=cur;i<=end;++i)
        {
            swap(nums[i],nums[cur]);
            full_permutation(nums,cur+1,end);
            swap(nums[i],nums[cur]);
        }
    }
}

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
            cin>>nums[i];
        full_permutation(nums,0,n-1);
    }
    return 0;
}
