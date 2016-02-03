/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-30-08.55
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
    int lengthOfLongestSubstring(string s)
    {
        int pos[500];
        int maxAns=0;
        bool has[500];
        int len=s.length();
        int maxRepeatPos=0;
        memset(pos,0,sizeof pos);
        memset(has,false,sizeof has);
//        bool isSubString=true;
        int SubLength=0;
        for(int i=0;i<len;++i)
        {
            if(has[s[i]])
            {
                maxAns=max(maxAns,i-max(pos[s[i]],maxRepeatPos));
                SubLength=i-max(pos[s[i]],maxRepeatPos);
                maxRepeatPos=pos[s[i]];
                pos[s[i]]=i;
            }
            else
            {
                has[s[i]]=true;
                pos[s[i]]=i;
                ++SubLength;
                maxAns=max(maxAns,SubLength);
            }
        }
        return maxAns;
    }
};

int main()
{
    string s;
    while(cin>>s)
    {
        cout<<"length is "<<s.length()<<endl;
        Solution solution;
        cout<<solution.lengthOfLongestSubstring(s)<<endl;
    }
    return 0;
}
