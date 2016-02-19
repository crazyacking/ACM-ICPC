/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-19-11.06
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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        vector<int> ve;
        ListNode *tptr=head;
        while(head)
        {
            ve.push_back(head->val);
            head=head->next;
        }

        if(ve.size()<k) return tptr;
        delete(head);
        int frontIndex=0,backIndex=k-1;
        while(frontIndex<ve.size() && backIndex<ve.size())
        {
            int low=frontIndex,high=backIndex;
            while(low<high)
            {
                swap(ve[low],ve[high]);
                ++low,--high;
            }
            frontIndex=backIndex+1;
            backIndex+=k;
        }

        int isFirst=1;
        ListNode *res=nullptr,*p=nullptr;
        for(int i=0; i<ve.size(); ++i)
        {
            if(isFirst)
            {
                isFirst=0;
                p=new ListNode(ve[i]);
                res=p;
            }
            else
            {
                p->next=new ListNode(ve[i]);
                p=p->next;
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int n,k;
    while(cin>>n>>k)
    {
        bool isFirst=1;
        ListNode *res=nullptr,*head=nullptr;
        for(int i=0; i<n; ++i)
        {
            int tmp;
            cin>>tmp;
            if(isFirst)
            {
                isFirst=0;
                head=new ListNode(tmp);
                res=head;
            }
            else
            {
                head->next=new ListNode(tmp);
                head=head->next;
            }
        }
        ListNode *ans=solution.reverseKGroup(res,k);
        while(ans)
        {
            cout<<ans->val<<" ";
            ans=ans->next;
        }
        cout<<"End."<<endl;
    }
    return 0;
}
/*

*/
