<<<<<<< HEAD
<<<<<<< HEAD
=======
#include<bits/stdc++.h>
using namespace std;
=======
>>>>>>> 37714f7b0992c5a9ab165acb59b4170e0f0287fe
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
<<<<<<< HEAD
=======
#include<bits/stdc++.h>
using namespace std;
>>>>>>> 5446e1b223acc359e01baf5cfca966d1fe6a298c
=======
>>>>>>> 89207da204b8acc59fd38dc4662ad168082fb381
>>>>>>> 37714f7b0992c5a9ab165acb59b4170e0f0287fe

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
<<<<<<< HEAD
<<<<<<< HEAD
=======
        int ans=0;
        int len=s.length();
        int currentLength=0;
        int recentCycleIndex=0;
        map<char,int> mp;
        for(int i=0; i<len; ++i)
        {
            if(mp.find(s[i])==mp.end())
                currentLength++;
            else
            {
                if(mp[s[i]]<=recentCycleIndex)
                    currentLength=i-recentCycleIndex;
                else
                    currentLength=i-mp[s[i]];
                recentCycleIndex=max(recentCycleIndex,mp[s[i]]);
            }
            mp[s[i]]=i;
            ans=max(ans,currentLength);
        }
        return ans;
=======
>>>>>>> 37714f7b0992c5a9ab165acb59b4170e0f0287fe
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
<<<<<<< HEAD
=======
        int ans=0;
        int len=s.length();
        int currentLength=0;
        int recentCycleIndex=0;
        map<char,int> mp;
        for(int i=0; i<len; ++i)
        {
            if(mp.find(s[i])==mp.end())
                currentLength++;
            else
            {
                if(mp[s[i]]<=recentCycleIndex)
                    currentLength=i-recentCycleIndex;
                else
                    currentLength=i-mp[s[i]];
                recentCycleIndex=max(recentCycleIndex,mp[s[i]]);
            }
            mp[s[i]]=i;
            ans=max(ans,currentLength);
        }
        return ans;
>>>>>>> 5446e1b223acc359e01baf5cfca966d1fe6a298c
=======
>>>>>>> 89207da204b8acc59fd38dc4662ad168082fb381
>>>>>>> 37714f7b0992c5a9ab165acb59b4170e0f0287fe
    }
};

int main()
{
    string s;
    while(cin>>s)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        cout<<"length is "<<s.length()<<endl;
        Solution solution;
        cout<<solution.lengthOfLongestSubstring(s)<<endl;
=======
=======
>>>>>>> 37714f7b0992c5a9ab165acb59b4170e0f0287fe
        Solution solution;
        int answer=solution.lengthOfLongestSubstring(s);
        cout<<"===========answer============"<<endl;
        cout<<answer<<endl;
<<<<<<< HEAD
>>>>>>> 5446e1b223acc359e01baf5cfca966d1fe6a298c
=======
=======
        cout<<"length is "<<s.length()<<endl;
        Solution solution;
        cout<<solution.lengthOfLongestSubstring(s)<<endl;
>>>>>>> 89207da204b8acc59fd38dc4662ad168082fb381
>>>>>>> 37714f7b0992c5a9ab165acb59b4170e0f0287fe
    }
    return 0;
}
