/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-17-09.57
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
    map<char,string> mp;
    vector<string> letterCombinations(string digits)
    {
        mp['0']=string(" ");
        mp['1']=string("");
        mp['2']=string("abc");
        mp['3']=string("def");
        mp['4']=string("ghi");
        mp['5']=string("jkl");
        mp['6']=string("mno");
        mp['7']=string("pqrs");
        mp['8']=string("tuv");
        mp['9']=string("wxyz");

        vector<int>cntBase;
        vector<string> res;
        int len=digits.length();
        if(len<=0) return res;
        for(int i=0;i<len;++i)
            cntBase.push_back(0);

        string tmp;
        while(cntBase[0]<mp[digits.at(0)].length())
        {
            tmp.clear();
            for(int i=0;i<len;++i)
            {
                tmp.push_back(mp[digits.at(i)][cntBase[i]]);
            }
            res.push_back(tmp);
            cntBase[len-1]++;
            // check and carry
            int carry=0;
            for(int i=len-1;i>0;--i)
            {
                cntBase[i]+=carry;
                carry=cntBase[i] / (mp[digits.at(i)].length());
                cntBase[i]%=(mp[digits.at(i)].length());
            }
            cntBase[0]+=carry;
        }
        return res;
    }
};
int main()
{
    Solution solution;
    string s;
    while(cin>>s)
    {
        auto ve=solution.letterCombinations(s);
        for(auto p:ve)
            cout<<p<<endl;
    }
    return 0;
}
/*

*/
