/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-09-13.57
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
    Solution()
    {
        graph.clear();
    }

    void add_edge(int k,vector<int> nums)
    {
        graph[k]=nums;
    }

    void bfs_search(int key)
    {
        set<int> result; // �洢��
        unordered_set<int> que; // ʹ��unordered_set����Ϊbfs���У�������ȥ�ص����ã�����������
        que.insert(key);
        while(que.size()>0)
        {
            int top=*que.begin();
            que.erase(top);
            if(!graph.count(top)) //  topû���ӽڵ��ˣ�ΪҶ�ӽڵ�
            {
                result.insert(top);
                continue;
            }
            for(auto p:graph[top])
                que.insert(p);
        }

        for(auto ptr:result)
            cout<<ptr<<" ";
        cout<<endl;
        cout<<"---------------------"<<endl;
    }
private:
    map<int,vector<int>> graph; //�洢����ͼ
};

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        while(n--)
        {
            int k,m;
            cin>>k>>m; // ����������¼�У���m����������k
            vector<int> nums(m);
            for(int i=0;i<m;++i)
                cin>>nums[i];
            solution.add_edge(k,nums);
        }
        int key;
        cin>>key; // Ҫ��ѯ��������
        solution.bfs_search(key);
    }
    return 0;
}
/*

�������ݣ�
4
1 2  2 3
2 2  3 4
4 2  5 6
7 2  8 9
1
*/
