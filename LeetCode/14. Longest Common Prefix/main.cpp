/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-16-12.27
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
    string longestCommonPrefix(vector<string>& strs)
    {
        string ret;
        int si=strs.size();
        if(si<=0) return ret;
        bool flag=0;
        for(int i=0;i<strs[0].length();++i)
        {
            for(int j=1;j<si;++j)
            {
                if(strs[j].length()<i || strs[j][i]!=strs[0][i])
                {
                    flag=1;
                    break;
                }
            }
            if(flag) break;
            ret.push_back(strs[0][i]);
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    int n;
    while(cin>>n)
    {
        vector<string> strs;
        while(n--)
        {
            string tmp;
            cin>>tmp;
            strs.push_back(tmp);
        }
        cout<<solution.longestCommonPrefix(strs)<<endl;
    }
    return 0;
}
