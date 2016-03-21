/**
* -----------------------------------------------------------------
* Copyright (c) 2016 crazyacking.All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Date  : 2016-03-16-09.31
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
#include <bits/stdc++.h>
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
   bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
   {
       unordered_map<int,vector<int>> graph;
       build_graph(prerequisites,graph);
       unordered_set<int> zero;
       vector<int> in_degree(numCourses,0);
       count_degree(graph,zero,in_degree);

       while(zero.size()>0)
       {
           int cur=*zero.begin();
           zero.erase(cur);
           for(auto ptr:graph[cur])
           {
               --in_degree[ptr];
               if(!in_degree[ptr])
                   zero.insert(ptr);
           }
       }
       for(auto ptr:in_degree)
           if(ptr>0) return false;
       return true;
   }
   void build_graph(auto& prerequisites,auto& graph)
   {
       for(auto ptr:prerequisites)
           graph[ptr.second].push_back(ptr.first);
   }
   void count_degree(auto& graph,auto& zero,auto& in_degree)
   {
       for(auto ptr1:graph)
           for(auto ptr2:ptr1.second)
               ++in_degree[ptr2];
       for(int i=0;i<in_degree.size();++i)
           if(!in_degree[i]) zero.insert(i);
   }
};

int main()
{
   int num,n;
   while(cin>>num>>n)
   {
       vector<pair<int, int>> prerequisites(n);
       for(int i=0;i<n;++i)
           cin>>prerequisites[i].first>>prerequisites[i].second;
       Solution solution;
       bool res=solution.canFinish(num,prerequisites);
       if(res) cout<<"Yes."<<endl;
       else cout<<"No."<<endl;
   }
   return 0;
}
/*

*/






bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    /**< matrix的第二维没必要用unordered_set，因为不管用不用hash都得扫一遍，用hash反而更慢 */
    vector<unordered_set<int>> matrix(numCourses); // save this directed graph
    for(int i = 0; i < prerequisites.size(); ++ i)
        matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

    vector<int> d(numCourses, 0); // in-degree
    for(int i = 0; i < numCourses; ++ i)
        for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
            ++ d[*it];

    for(int j = 0, i; j < numCourses; ++ j)
    {
        /**< 这儿可以动态维护一个set，存放入度为0的结点，就不必每次都从头开始找了 */
        for(i = 0; i < numCourses && d[i] != 0; ++ i); // find a node whose in-degree is 0

        if(i == numCourses) // if not find
            return false;

        d[i] = -1;
        for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
            -- d[*it];
    }
    return true;
}


class Solution
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        /**< matrix的第二维没必要用unordered_set，因为不管用不用hash都得扫一遍，用hash反而更慢 */
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++)
        {
            int j = 0;
            /**< 这儿可以动态维护一个set，存放入度为0的结点，就不必每次都从头开始找了 */
            for (; j < numCourses; j++)
                if (!degrees[j]) break;
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j])
                degrees[neigh]--;
        }
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    vector<int> compute_indegree(vector<unordered_set<int>>& graph)
    {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};
