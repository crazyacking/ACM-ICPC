/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights headerved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-17-16.50
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

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *res=NULL,*head=NULL;
        bool isFirst=true;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                if(isFirst)
                {
                    head=new ListNode(l1->val);
                    res=head;
                    isFirst=false;
                }
                else
                {
                    head->next=new ListNode(l1->val);
                    head=head->next;
                }
                l1=l1->next;
            }
            else
            {
                if(isFirst)
                {
                    head=new ListNode(l2->val);
                    res=head;
                    isFirst=false;
                }
                else
                {
                    head->next=new ListNode(l2->val);
                    head=head->next;
                }
                l2=l2->next;
            }
        }

        while(l1)
        {
            if(isFirst)
            {
                head=new ListNode(l1->val);
                res=head;
                isFirst=false;
            }
            else
            {
                head->next=new ListNode(l1->val);
                head=head->next;
            }
            l1=l1->next;
        }
        while(l2)
        {
            if(isFirst)
            {
                head=new ListNode(l2->val);
                res=head;
                isFirst=false;
            }
            else
            {
                head->next=new ListNode(l2->val);
                head=head->next;
            }
            l2=l2->next;
        }
        return res;
    }
};

int main()
{

    return 0;
}
/*

*/
