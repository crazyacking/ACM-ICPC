/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-27-11.44
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

string s;

int cnt(string& res)
{
    int l=res.length();
    int ans=0;
    while(1)
    {
        int len=res.length();
        bool flag=0;
        for(int i=0;i<len;++i)
        {
            if(i==0);
            else
            {
                if(res[i]==res[i-1])
                {
                    flag=1;
                    int sta=i-1;
                    int j=i;
                    while(j<len && res[j]==res[j-1])
                        ++j;
                    int en=j-1;
                    res=res.substr(0,sta)+res.substr(en,res.length());
                }

            }
        }
        if(!flag)
            break;
    }
    return l-res.length();
}


int work(int x)
{
    string ls=s.substr(0,x);
    cout<<ls<<endl;
    string rs=s.substr(x,s.length());
    cout<<rs<<endl;
    puts("===============================Program Run Here !=============================");

    char ch='A';
    int ans=0;
    for(int i=0;i<3;++i)
    {
        ch=ch+i;
        string res=ls+ch+rs;
        ans=max(ans,cnt(res));
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        s.clear();
        cin>>s;
        int len=s.length();
        int ans=0;
        for(int i=0;i<=len;++i)
        {
            ans=max(ans,work(i));
        }
    }
    return 0;
}
/*

*/


