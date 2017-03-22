/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-16-08.31
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
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

class Solution
{
public:

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        if(!prerequisites.size()) return true;
        unordered_set<int> se;
        for(int i=0;i<prerequisites.size();++i)
        {
            se.insert(prerequisites[i].first);
        }
        for(int i=0;i<prerequisites.size();++i)
        {
            if(se.count(prerequisites[i].second))
                se.erase(prerequisites[i].second);
        }
//        puts("===============================Program Run Here !=============================");

//        for(auto ptr:se)
//            cout<<ptr<<" ";
//        cout<<endl;

        if(se.size()==0) return false;
        sort(prerequisites.begin(),prerequisites.end());
        unordered_map<int,int> begin_idx;
        for(int i=prerequisites.size()-1;i>=0;--i)
            begin_idx[prerequisites[i].first]=i;

        queue<int> que;
        for(auto p:se)
            que.push(p);
        unordered_map<int,bool> mp;
        while(!que.empty())
        {
            int now=que.front();
            que.pop();
            mp[now]=true;
            int idx=begin_idx[now];
//            cout<<"idx="<<idx<<endl;
            for(int i=idx;prerequisites[i].first==now;++i)
            {
                int sec=prerequisites[i].second;
                if(mp[sec])
                    return false;
                que.push(sec);
            }
        }
        return true;
    }
};

int main() {
    int num;
    while(cin>>num)
    {
        int from,to;
        vector<pair<int,int>> tve;
        for(int i=0;i<num;++i)
        {
            cin>>from>>to;
            tve.push_back(make_pair(from,to));
        }
        Solution solution;
        if(solution.canFinish(num,tve))
            cout<<"Yes."<<endl;
        else cout<<"No."<<endl;
    }
    return 0;
}
/*

*/
