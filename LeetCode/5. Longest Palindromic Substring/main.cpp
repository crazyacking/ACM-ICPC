/**
 * -----------------------------------------------------------------
 * Copyright (c) 2015 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2015-12-10-11.04
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


/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution
{
public:
    /** O(n)内求出所有回文串
     *原串 :abaaba
     *Ma串 :.,a,b,a,a,b,a,
     *Mp[i]:Ma串中，以字符Ma[i]为中心的最长回文子串的半径长度(包括Ma[i],也就是把回文串对折后的长度).
     ****经过对原串扩展处理后，将奇数串的情况也合并到了偶数的情况(不需要考虑奇数串)
     */
    const static int MAXN=1010;
    char Ma[MAXN*2],s[MAXN];
    int Mp[MAXN*2],Mplen;
    void Manacher(string s)
    {
          memset(Ma,'\0',sizeof Ma);
          int len=s.length();
          int le=0;
          Ma[le++]='.';
          Ma[le++]=',';
          for(int i=0;i<len;++i)
          {
                Ma[le++]=s.at(i);
                Ma[le++]=',';
          }
          Mplen=le;
          Ma[le]=0;
          int pnow=0,pid=0;
          for(int i=1;i<le;++i)
          {
                if(pnow>i)
                      Mp[i]=min(Mp[2*pid-i],pnow-i);
                else
                      Mp[i]=1;
                for(;Ma[i-Mp[i]]==Ma[i+Mp[i]];++Mp[i]);
                if(i+Mp[i]>pnow)
                {
                      pnow=i+Mp[i];
                      pid=i;
                }
          }
    }

    string longestPalindrome(string s)
    {
        int idx=0;
        int MaxPalindomLength=1;
        Manacher(s);
        for(int i=0;i<Mplen;++i)
        {
            if(Mp[i]>MaxPalindomLength)
                MaxPalindomLength=Mp[i],idx=i;
        }
        --MaxPalindomLength;
        int startPos=idx-MaxPalindomLength+1;
        char str[MAXN];
        int strLen=0;
        for(int i=startPos;strLen<MaxPalindomLength;i+=2)
            str[strLen++]=Ma[i];
        str[strLen]='\0';
        return string(str);
    }
};

int main()
{
    Solution solution;
    string s;
    while(cin>>s)
    {
        cout<<solution.longestPalindrome(s)<<endl;
    }
    return 0;
}
