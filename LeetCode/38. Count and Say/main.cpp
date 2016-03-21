///**
// * -----------------------------------------------------------------
// * Copyright (c) 2016 crazyacking.All rights reserved.
// * -----------------------------------------------------------------
// *       Author: crazyacking
// *       Date  : 2016-03-05-16.58
// */
//#include <queue>
//#include <cstdio>
//#include <set>
//#include <string>
//#include <stack>
//#include <cmath>
//#include <climits>
//#include <map>
//#include <cstdlib>
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//typedef long long(LL);
//typedef unsigned long long(ULL);
//const double eps(1e-8);
//
//
//class Solution
//{
//public:
//    string countAndSay(int n)
//    {
//        string ret;
//        ret.push_back('1');
//        return solve(ret,n);
//    }
//
//    string solve(string& str,int n)
//    {
//        if(n==1)
//            return str;
//        int len=str.length();
//        string ret;
//        for(int i=1; i<len; ++i)
//        {
//            int cnt=1;
//            while(i<len && str[i]==str[i-1])
//            {
//                ++cnt;
//                ++i;
//            }
//            ret.push_back(char(cnt+'0'));
//            ret.push_back(str[i-1]);
//        }
//
//        if(len>2)
//        {
//            if(str[len-1]!=str[len-2])
//            {
//                ret.push_back(char(1+'0'));
//                ret.push_back(str[len-1]);
//            }
//        }
//        else if(len==2)
//        {
//            if(str[1]!=str[0])
//            {
//                ret.push_back(char(1+'0'));
//                ret.push_back(str[len-1]);
//            }
//
//        }
//        else
//        {
//            ret.push_back(char(1+'0'));
//            ret.push_back(str[0]);
//        }
//        return solve(ret,n-1);
//    }
//};
//
//int main()
//{
//    int n;
//    while(cin>>n)
//    {
//        Solution solution;
//        cout<<solution.countAndSay(n)<<endl;
//    }
//    return 0;
//}
///*
//
//*/



/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-05-17.33
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
#include <bits/stdc++.h>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


class Solution
{
public:
    string countAndSay(int n)
    {
        if(n==0)
            return string("");
        string ret="1";
        string str;
        while(--n)
        {
            str.clear();
            for(int i=0;i<ret.size();++i)
            {
                int cnt=1;
                while(i+1<ret.size() &&ret[i]==ret[i+1])
                    ++cnt,++i;
                str.push_back(char(cnt+'0'));
                str+=ret[i];
            }
            ret=str;
        }
        return ret;
    }
};


int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        cout<<solution.countAndSay(n)<<endl;
    }
    return 0;
}
/*

*/
