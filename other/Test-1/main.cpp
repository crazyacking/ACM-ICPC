/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-16-20.41
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        vector<vector<int> > res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            if(target < 0)
                break;

            while (front < back)
            {
                int sum = nums[front] + nums[back];
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else
                {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[front];
                    triplet[2] = nums[back];
                    res.push_back(triplet);
                    while (front < back && nums[front] == triplet[1]) front++;
                    while (front < back && nums[back] == triplet[2]) back--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return res;
    }
};
int main()
{
    Solution solution;
    int n;
    while(cin>>n)
    {
        vector<int> ve;
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            ve.push_back(tmp);
        }
        vector<vector<int> > ans=solution.threeSum(ve);
        for(auto p:ans)
        {
            for(auto q:p)
            {
                cout<<q<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
