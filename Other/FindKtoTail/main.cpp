#include <bits/stdc++.h>
using namespace std;

struct LinkNode
{
    int val;
    LinkNode* next_Node;
    LinkNode(int v)
    {
        val=v;
        next_Node=nullptr;
    }
};

class Solution
{
public:
    LinkNode* FindKtoTail(LinkNode* head,int k)
    {
        LinkNode *tail=head;
        for(int i=0;i<k;++i)
        {
            tail=tail->next_Node;
            if(!tail)
                break;
        }
        LinkNode *front=head;
        while(tail)
        {
            tail=tail->next_Node;
            front=front->next_Node;
        }
        return front;
    }
};

int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        LinkNode *head,*p;
        int temp;
        for(int i=0;i<n;++i)
        {
            cin>>temp;
             if(i==0)
             {
                 p=new LinkNode(temp);
                 head=p;
                 continue;
             }
             p->next_Node=new LinkNode(temp);
             p=p->next_Node;
        }
        Solution solution;
       LinkNode *ans=solution.FindKtoTail(head,k);
       if(ans)
           cout<<ans->val<<endl;
    }
    return 0;
}
