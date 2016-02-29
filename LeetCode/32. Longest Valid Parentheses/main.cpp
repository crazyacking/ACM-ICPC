/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-20-13.51
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
        int n = s.length(), longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                if (!st.empty())
                {
                    if (s[st.top()] == '(') st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        if (st.empty()) longest = n;  // Matching exact
        else // can't Matching exact
        {
            int a = n, b = 0;
            while(!st.empty())
            {
                b = st.top();
                st.pop();
                longest = max(longest, a-b-1);
                a = b;
            }
            longest = max(longest, a);
        }
        return longest;
    }
};


int main()
{
    string str;
        while(cin>>str)
    {
        Solution solution;
        cout<<solution.longestValidParentheses(str)<<endl;
    }
    return 0;
}
/*

*/
