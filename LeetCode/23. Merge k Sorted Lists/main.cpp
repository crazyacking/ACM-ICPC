/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-18-09.02
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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        vector<int> nodeVal;
        for(auto ptr:lists)
        {
            while(ptr)
            {
                nodeVal.push_back(ptr->val);
                ptr=ptr->next;
            }
        }
        if(nodeVal.size()<=0)
        {
            return nullptr;
        }

        sort(nodeVal.begin(),nodeVal.end());
        bool isFirst=1;
        ListNode *res=nullptr,*head=nullptr;
        for(auto p:nodeVal)
        {
            if(isFirst)
            {
                isFirst=0;
                head=new ListNode(p);
                res=head;
            }
            else
            {
                head->next=new ListNode(p);
                head=head->next;
            }
        }
        return res;
    }
};

ListNode* getList(vector<int>& arr)
{
    bool isFirst=1;
    ListNode *res=nullptr,*head=nullptr;
    for(auto p:arr)
    {
        if(isFirst)
        {
            isFirst=0;
            head=new ListNode(p);
            res=head;
        }
        else
        {
            head->next=new ListNode(p);
            head=head->next;
        }
    }
    return res;
}

int main()
{
    Solution solution;
    int n;
    while(cin>>n)
    {
        vector<ListNode*> listVe;
        while(n--)
        {
            int num;
            cin>>num;
            vector<int> ve;
            for(int i=0;i<num;++i)
            {
                int tmp;
                cin>>tmp;
                ve.push_back(tmp);
            }
            listVe.push_back(getList(ve));
        }
        ListNode* head=solution.mergeKLists(listVe);
        while(head)
        {
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<"End."<<endl;
    }
    return 0;
}
/*

*/
