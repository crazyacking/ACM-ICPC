/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-17-17.58
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
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        recursive(res,"",n,0);
        return res;
    }
    void recursive(vector<string>& v,string str,int n,int m)
    {
        if(n==0 && m==0)
        {
            v.push_back(str);
            return;
        }
        if(m>0)
            recursive(v,str+")",n,m-1);
        if(n>0)
            recursive(v,str+"(",n-1,m+1);
    }
};

int main()
{
    Solution solution;
    int n;
    while(cin>>n)
    {
        auto ans=solution.generateParenthesis(n);
        for(auto p:ans)
        {
            cout<<p<<endl;
        }
        cout<<"End."<<endl;
    }
    return 0;
}
/*

*/
