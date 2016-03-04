/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-04-21.38
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
    int minNumberInRotateArray(vector<int> rotateArray)
    {
		int len=rotateArray.size();
		if(len==0)
			return 0;
		int low=0,high=len-1;
		int minIdx=0;
		while(rotateArray[low]>=rotateArray[high])
		{
		    if(high-low==1)
		    {
		        minIdx=high;
		        break;
		    }
			int mid=(low+high)>>1;
			if(rotateArray[low]==rotateArray[high] && rotateArray[mid]==rotateArray[low])
                return findMin(rotateArray,low,high);
			if(rotateArray[mid]>=rotateArray[low])
				low=mid;
			else if(rotateArray[mid]<=rotateArray[high])
				high=mid;
		}
		return rotateArray[minIdx];
    }

    int findMin(vector<int>& rotateArray,int l,int r)
    {
        int m=INT_MAX;
        for(int i=l;i<=r;++i)
            m=min(m,rotateArray[i]);
        return m;
    }
};

int main()
{
    int n,k;
    while(cin>>n)
    {
        vector<int> ve;
        while(n--)
        {
            cin>>k;
            ve.push_back(k);
        }
        Solution solution;
        int ans=solution.minNumberInRotateArray(ve);
        cout<<ans<<endl;
        return 0;
    }
}
    /*

    */
