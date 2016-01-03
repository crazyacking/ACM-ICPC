#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {}
};
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution
{
public:
    vector<int> printListFromTailToHead(struct ListNode* head)
    {
        vector<int> ans;
        while(head!=NULL)
        {
            ans.push_back((head->val));
            head=head->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
    return 0;
}
