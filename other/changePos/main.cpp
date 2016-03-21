#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void  changePos(vector<int> & nums)
    {
        int len=nums.size();
        int i=0,j=len-1;
        while(i<j)
        {
            if(nums[i]%2==0 && nums[j]%2==1)
                swap(nums[i],nums[j]);
            if(nums[i]%2!=0)
                ++i;
            if(nums[j]%2!=1)
                --j;
        }
    }
};
int main()
{
    int n;
    while(cin>>n)
    {
         vector<int> ve(n);
         for(int i=0;i<n;++i)
             cin>>ve[i];
         Solution solution;
         solution.changePos(ve);
         for(int i=0;i<n;++i)
             cout<<ve[i]<<" ";
         cout<<endl;
    }
    return 0;
}
