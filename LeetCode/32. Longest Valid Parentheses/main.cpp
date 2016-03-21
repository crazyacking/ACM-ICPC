/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-01-20.35
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
    int longestValidParentheses(string s)
    {
        int len=s.length();
        stack<pair<char,int>> sta;
        for(int i=0;i<len;++i)
        {
            if(s[i]=='(')
                sta.push(make_pair('(',i));
            else
            {
                if(!sta.empty())
                {
                    pair<char,int> t=sta.top();
                    if(t.first=='(')
                        sta.pop();
                    else
                        sta.push(make_pair(')',i));
                }
                else
                    sta.push(make_pair(')',i));
            }
        }

        int ans=0,frontVal=len,backVal;
        if(!sta.empty() &&sta.top().second!=len-1)
            backVal=len;
        else
            backVal=len-1;
        while(!sta.empty())
        {
            pair<char,int> t=sta.top();
            sta.pop();
            frontVal=t.second;
            ans=max(ans,backVal-frontVal-1);
            backVal=frontVal;
        }
        ans=max(ans,frontVal-0);
        return ans;
    }
};

int main()
{
    Solution solution;
    string s;
    while(cin>>s)
    {
        cout<<solution.longestValidParentheses(s)<<endl;
    }
    return 0;
}
/*

*/
