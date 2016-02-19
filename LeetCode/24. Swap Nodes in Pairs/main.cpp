/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-19-10.35
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
    ListNode* swapPairs(ListNode* head)
    {
        if(!head) return nullptr;
        ListNode *frontPtr=head,*backPtr=head->next;
        while(frontPtr && backPtr)
        {
            swap(frontPtr->val,backPtr->val);

            frontPtr=frontPtr->next;
            if(frontPtr!=nullptr)
                frontPtr=frontPtr->next;

            backPtr=backPtr->next;
            if(backPtr!=nullptr)
                backPtr=backPtr->next;
        }
        return head;
    }
};

int main()
{

    return 0;
}
/*

*/
