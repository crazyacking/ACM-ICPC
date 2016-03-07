/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-06-17.13
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
#include <windows.h>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string res="0";
        int begin=0;
        for(int i=0;i<num2.length();++i)
        {
            string temp_res;
            str_num_multi(num1,num2[i]-'0',temp_res);
            add(res,temp_res,begin);
            begin++;
        }
        reverse(res.begin(),res.end());
        // delete leader zero
        while(res.size()>0 && res[0]=='0')
        {
            res.pop_back();
        }
        if(res.size()==0) res.push_back(char('0'));
        return res;
    }

    void str_num_multi(string str,int num,string& res)
    {
        int carry=0;
        for(int i=0;i<str.length();++i)
        {
            int now=num*(str[i]-'0')+carry;
            carry=now/10;
            now%=10;
            res.push_back(char(now+'0'));
        }
        if(carry)
            res.push_back(char(carry+'0'));
    }

    void add(string& res,string num,int begin)
    {
        int len=num.length(),carry=0,now;
        for(int i=0;i<len;++i)
        {
            if(begin<res.size())
                now=(res[begin]-'0')+(num[i]-'0')+carry;
            else now=carry+(num[i]-'0');
            carry=now/10;
            now%=10;
            if(begin>=res.size())
                res.push_back(char(now+'0'));
            else
                res[begin]=now+'0';
            ++begin;
        }

        while(carry)
        {
            if(begin<res.size())
                now=carry+(res[begin]-'0');
            else now=carry;
            carry=now/10;
            now%=10;
            if(begin>=res.size())
            {
                res.push_back(char(now+'0'));
            }
            else
                res[begin]=now+'0';
            ++begin;
        }
    }
};

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        Solution solution;
        string ans=solution.multiply(s1,s2);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
