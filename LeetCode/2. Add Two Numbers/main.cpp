/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-29-16.16
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
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int jinwei = 0;
        ListNode *h1 = l1;
        ListNode *h2 = l2;
        ListNode *ans, *ret;
        bool isFirst = true;
        while (h1 && h2) {

            int val = h1->val + h2->val + jinwei;
            int now = val % 10;
            jinwei = val / 10;
            if (isFirst) {
                ans = new ListNode(now);
                ret = ans;
                isFirst = false;
            } else {
                ans->next = new ListNode(now);
                ans = ans->next;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
        while (h1) {
            int val = h1->val + jinwei;
            int now = val % 10;
            jinwei = val / 10;
            if (isFirst) {
                ans = new ListNode(now);
                ret = ans;
                isFirst = false;
            } else {
                ans->next = new ListNode(now);
                ans = ans->next;
            }
            h1 = h1->next;
        }
        while (h2) {
            int val = h2->val + jinwei;
            int now = val % 10;
            jinwei = val / 10;
            if (isFirst) {
                ans = new ListNode(now);
                ret = ans;
                isFirst = false;
            } else {
                ans->next = new ListNode(now);
                ans = ans->next;
            }
            h2 = h2->next;
        }
        while (jinwei) {
            ans->next = new ListNode(jinwei % 10);
            jinwei /= 10;
            ans = ans->next;
        }
        return ret;
    }
};

class Solution1 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans, *now;
        int carry = 0, current = 0, temp = 0;
        bool first = true;
        while (l1 && l2) {
            temp = l1->val + l2->val + carry;
            carry = temp / 10;
            current = temp % 10;
            if (first) {
                now = new ListNode(current);
                ans = now;
                first = false;
            } else {
                now->next = new ListNode(current);
                now = now->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            temp = l1->val + carry;
            carry = temp / 10;
            current = temp % 10;
            now->next = new ListNode(current);
            now = now->next;
            l1 = l1->next;
        }

        while (l2) {
            temp = l2->val + carry;
            carry = temp / 10;
            current = temp % 10;
            now->next = new ListNode(current);
            now = now->next;
            l2 = l2->next;
        }

        if (carry > 0) {
            now->next = new ListNode(1);
        }
        return ans;
    }
};

int main() {
    int n1, n2;
    while (cin >> n1 >> n2) {
        ListNode *h1, *head1;
        ListNode *h2, *head2;
        int tmp;
        for (int i = 0; i < n1; ++i) {
            cin >> tmp;
            if (!i) {
                h1 = new ListNode(tmp);
                head1 = h1;
            } else {
                h1->next = new ListNode(tmp);
                h1 = h1->next;
            }
        }

        for (int i = 0; i < n2; ++i) {
            cin >> tmp;
            if (!i) {
                h2 = new ListNode(tmp);
                head2 = h2;
            } else {
                h2->next = new ListNode(tmp);
                h2 = h2->next;
            }
        }

        Solution1 solution;
        ListNode *ans = solution.addTwoNumbers(head1, head2);
        puts("----------------------");
        while (ans) {
            cout << ans->val;
            ans = ans->next;
        }
        cout << endl;
    }
    return 0;
}

/*
3 3
2 4 3
5 6 4
*/