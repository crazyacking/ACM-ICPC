#include <bits/stdc++.h>
using namespace std;


struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};
class Solution
{
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		ListNode *res,*back;
		res=back=pListHead;
		while(k)
		{
			if(back==NULL)
			{
				return NULL;
			}
			back=back->next;
			--k;
		}
		while(back)
		{
			back=back->next,res=res->next;
		}
		return res;
	}
};



int main(int argc, char const *argv[])
{
	int n,k;
	while(cin>>n>>k)
	{
		ListNode *head,*p;
		for(int i=0;i<n;++i)
		{
			int tmp_val;
			cin>>tmp_val;
			if(!i)
			{
				head=new ListNode(tmp_val);
				p=head;
			}
			else
			{
				head->next=new ListNode(tmp_val);
				head=head->next;
			}
		}
		Solution solution;
		ListNode* ans=solution.FindKthToTail(p,k);
		if(!ans)
			cout<<"error"<<endl;
		else
			cout<<(ans->val)<<endl;
	}
	return 0;
}