/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-17-13.51
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        vector<int> list;
        while(head)
        {
            list.push_back(head->val);
            head=head->next;
        }
        int si=list.size();
        if(si<=1) return head;
        // calculate the idx
        int idx=si-n;
        ListNode* ret;
        ListNode* tmp=ret;
        bool isFirst=true;
        for(int i=0; i<si; ++i)
        {
            if(i==idx)
                continue;
            if(isFirst)
            {
                tmp=new ListNode(list[i]);
                ret=tmp;
                isFirst=false;
            }
            else
            {
                tmp->next=new ListNode(list[i]);
                tmp=tmp->next;
            }
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    int n,num,tmp;
    while(cin>>n>>num)
    {
        ListNode* head=NULL,*root=NULL;
        for(int i=0; i<n; ++i)
        {
            cin>>tmp;
            if(i==0)
            {
                head=new ListNode(tmp);
                root=head;
            }
            else
            {
                head->next=new ListNode(tmp);
                head=head->next;
            }
        }

        ListNode* ans=solution.removeNthFromEnd(root,num);
        while(ans)
        {
            cout<<ans->val<<" ";
            ans=ans->next;
        }
        cout<<endl;
        cout<<"End."<<endl;
    }
    return 0;
}
/*

*/
