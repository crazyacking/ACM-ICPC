/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-05-18.56
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum(candidates,res,combination,target,0);
        return res;
    }
private:
    void combinationSum(vector<int>& candidates,vector<vector<int>> &res,vector<int>& combination,int target,int begin)
    {
        if(!target)
        {
            res.push_back(combination);
            return;
        }
        for(int i=begin;target>=candidates[i] && i<candidates.size() ;++i)
        {
                combination.push_back(candidates[i]);
                combinationSum(candidates,res,combination,target-candidates[i],i+1);
                combination.pop_back();
        }
        return;
    }
};


int main()
{
    freopen("H:\\Code_Fantasy\\in.txt","r",stdin);
    int n,target;
    while(cin>>n>>target)
    {
        cout<<n<<" "<<target<<endl;
        vector<int> ve;
        for(int i=0; i<n; ++i)
        {
            int tmp;
            cin>>tmp;
            ve.push_back(tmp);
        }
        Solution solution;
        vector<vector<int>> ans=solution.combinationSum2(ve,target);
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
/*

*/
