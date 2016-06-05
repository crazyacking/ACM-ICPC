/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-05-22.10
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

//class Solution
//{
//public:
//    int trap(vector<int>& height)
//    {
//        int len=height.size(),front=0,res=0;
//        int max_height=0,max_idx=len-1;
//        for(int i=0;i<len;++i)
//        {
//            if(max_height<height[i])
//            {
//                max_height=height[i];
//                max_idx=i;
//            }
//        }
//
//        while(front<max_idx)
//        {
//            while(front+1<max_idx && height[front]<height[front+1])
//                ++front;
//            int stone=0;
//            int back=front+1;
//            while(back<max_idx && height[back]<height[front])
//            {
//                stone+=height[back];
//                ++back;
//            }
//            res+=(back-front-1)*height[front]-stone;
//            front=back;
//        }
//
//        int back=len-1;
//        while(back>max_idx)
//        {
//            while(back-1>max_idx && height[back]<height[back-1])
//                --back;
//            int stone=0;
//            int front=back-1;
//            while(front>max_idx && height[front]<height[back])
//            {
//                stone+=height[front];
//                --front;
//            }
//            res+=(back-front-1)*height[back]-stone;
//            back=front;
//        }
//        return res;
//    }
//};


class Solution
{
public:
    int trap(vector<int>& height)
    {
        int left=0,right=height.size()-1;
        int maxLeft=0,maxRight=0;
        int res=0;
        while(left<right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>maxLeft)
                    maxLeft=height[left];
                res+=maxLeft-height[left];
                left++;
            }
            else
            {
                if(height[right]>maxRight)
                    maxRight=height[right];
                res+=maxRight-height[right];
                right--;
            }
        }
        return res;
    }
};

int main()
{
    freopen("H:\\Code_Fantasy\\in.txt","r",stdin);
    int n;
    while(cin>>n)
    {
        cout<<n<<endl;
        vector<int> ve;
        for(int i=0; i<n; ++i)
        {
            int tempVal;
            cin>>tempVal;
            ve.push_back(tempVal);
        }
        Solution solution;
        cout<<solution.trap(ve)<<endl;
    }
    return 0;
}
/*

*/
