/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-15-16.34
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
    bool isPalindrome(int x)
    {
        if(x<0) return 0;
        char s[20];
        int cnt=0;
        while(x)
        {
            int tmp=x%10;
            x/=10;
            s[cnt++]=tmp+'0';
        }
        s[cnt]='\0';
        int len=strlen(s);
        int midLen=len/2;
        int endPos=len-1;
        for(int i=0;i<midLen;++i,--endPos)
        {
            if(s[i]!=s[endPos])
                return 0;
        }
        return 1;
    }
};

int main()
{
    Solution solution;
    int n;
    while(cin>>n)
    {
        if(solution.isPalindrome(n))
            puts("Yes.");
        else puts("No.");

    }
    return 0;
}
