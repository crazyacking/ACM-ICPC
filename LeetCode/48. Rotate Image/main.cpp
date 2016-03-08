#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        vector<vector<int>> res;
        for(int i=0;i<n;++i)
        {
            vector<int> nums(n);
            int cnt=0;
            for(int j=n-1;j>=0;--j)
                nums[cnt++]=matrix[j][i];
            res.push_back(nums);
        }
        matrix=res;
        return matrix;
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> matrix(n);
        for(int i=0;i<n;++i)
        {
            vector<int> nums(n);
            for(int j=0;j<n;++j)
            {
                cin>>nums[j];
            }
            matrix[i]=nums;
        }
        Solution solution;
        auto ans=solution.rotate(matrix);

        for(auto p1:ans)
            for(auto p2:p1)
                cout<<p2<<" ";
            cout<<endl;
    }
    return 0;
}
