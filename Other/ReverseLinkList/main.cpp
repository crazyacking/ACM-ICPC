#include <bits/stdc++.h>
using namespace std;

struct LinkNode
{
    int val;
    LinkNode *next;
    LinkNode(int v)
    {
        val=v;
        next=nullptr;
    }
};

class Solution
{
public:
    LinkNode* ReverseLinkList(LinkNode *head=nullptr)
    {
        if(!head || !head->next)
            return head;
        LinkNode *p1=head,*p2=head->next,*p3=head->next;
        p1->next=nullptr;
        while(p3)
        {
            p3=p3->next;
            p2->next=p1;
            p1=p2;
            if(!p3)
            {
                return p2;
            }
            p2=p3;
        }
        return p2;
    }
};


void printLinkList(LinkNode *head=nullptr)
{
    while(head)
    {
        cout<<(head->val)<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    int n;
    while(cin>>n)
    {
         LinkNode *head=nullptr,*p=nullptr;
         int temp;
         for(int i=0;i<n;++i)
         {
             cin>>temp;
             if(!i)
             {
                  p=new LinkNode(temp);
                  head=p;
             }
             else
             {
                 p->next=new LinkNode(temp);
                 p=p->next;
             }
         }
         Solution solution;
         LinkNode *ans=solution.ReverseLinkList(head);
         printLinkList(ans);
         if(ans!=NULL)
             delete(ans);
         cout<<"-------------"<<endl;
    }
    return 0;
}
