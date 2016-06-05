///**
// * -----------------------------------------------------------------
// * Copyright (c) 2016 crazyacking.All rights reserved.
// * -----------------------------------------------------------------
// *       Author: crazyacking
// *       Date  : 2016-03-05-21.30
// */
//#include <queue>
//#include <cstdio>
//#include <set>
//#include <string>
//#include <stack>
//#include <cmath>
//#include <climits>
//#include <map>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//typedef long long(LL);
//typedef unsigned long long(ULL);
//const double eps(1e-8);
//
//class Solution
//{
//public:
//    int firstMissingPositive(vector<int>& nums)
//    {
//        map<int,bool> mp;
//        for(int i=0;i<nums.size();++i)
//        {
//            if(nums[i]>0)
//                mp[nums[i]]=true;
//        }
//        if(mp.size()==0 || (*mp.begin()).first>1)
//            return 1;
//        for(int i=(*mp.begin()).first;1;++i)
//        {
//            if(mp.count(i)==0)
//                return i;
//        }
//    }
//};
//
//int main()
//{
//    int n;
//    while(cin>>n)
//    {
//        vector<int> ve;
//        for(int i=0;i<n;++i)
//        {
//            int tempVal;
//            cin>>tempVal;
//            ve.push_back(tempVal);
//        }
//        Solution solution;
//        cout<<solution.firstMissingPositive(ve)<<endl;
//    }
//    return 0;
//}
///*
//
//*/


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};
