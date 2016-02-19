/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-19-16.45
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
    int Next[100005];
    void getNext(string& s)
    {
        Next[0]=0;
        for(int i=1,k=0;i<s.length();++i)
        {
            while(s[i]!=s[k] && k)
                k=Next[k-1];
            if(s[i]==s[k])
                ++k;
            Next[i]=k;
        }
    }
    int strStr(string haystack, string needle)
    {
        if(needle.length()==0)
            return 0;
        getNext(needle);
        for(int i=0,k=0;i<haystack.length();++i)
        {
            while(haystack[i]!=needle[k] && k)
                k=Next[k-1];
            if(haystack[i]==needle[k])
                ++k;
            if(k==needle.length())
                return i-k+1;
        }
        return -1;
    }
};

int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        Solution solution;
        cout<<solution.strStr(str1,str2)<<endl;
    }
    return 0;
}
/*

*/
