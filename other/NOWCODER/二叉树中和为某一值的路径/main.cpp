#include "bits/stdc++.h"
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		vector<vector<int> > res(0);
		if(!root) return res;
		vector<int> nums;
		nums.push_back(root->val);
		int sum = root->val;
		dfs(root, expectNumber, nums, sum, res);
		return res;
	}

	void dfs(TreeNode *cur_node, int expectNumber, vector<int> &nums, int sum, vector<vector<int> > &res)
	{
		if (sum == expectNumber && (!cur_node->left && !cur_node->right))
			res.push_back(nums);
		if (cur_node->left)
		{
			nums.push_back(cur_node->left->val);
			dfs(cur_node->left, expectNumber, nums, sum + cur_node->left->val, res);
			nums.pop_back();
		}
		if (cur_node->right)
		{
			nums.push_back(cur_node->right->val);
			dfs(cur_node->right, expectNumber, nums, sum + cur_node->right->val, res);
			nums.pop_back();
		}
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root;
	root=new TreeNode(4);
	root->left=new TreeNode(3);
	root->right=new TreeNode(8);
	Solution solution;
	int expectNumber;
	while(cin>>expectNumber)
	{

		vector<vector<int> > res=solution.FindPath(root,expectNumber);
		for(vector<vector<int> > ::iterator it1=res.begin();it1!=res.end();++it1)
		{
			for(vector<int>::iterator it2=(*it1).begin();it2!=(*it1).end();++it2)
			{
				cout<<(*it2)<<" ";
			}
			cout<<endl;
		}
		cout<<"---------End.-----------"<<endl;
	}
	return 0;
}