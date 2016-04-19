#include "bits/stdc++.h"
using namespace std;



class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if(input.size()<k)
            return res;
		priority_queue<int> p_que;
		int si=input.size();
		for(int i=0;i<si;++i)
		{
			p_que.push(input[i]);
			if(p_que.size()>k)
				p_que.pop();
		}
		while(!p_que.empty())
		{
			res.push_back(p_que.top());
			p_que.pop();
		}
		return res;
	}
};



int main(int argc, char const *argv[])
{
	int n,k;
	while (cin >> n >> k)
	{
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>nums[i];
		}
		Solution solution;
		vector<int> res=solution.GetLeastNumbers_Solution(nums,k);
		for(vector<int>::iterator it=res.begin();it!=res.end();++it)
		{
			cout<<(*it)<<" ";
		}
		cout<<endl;

	}
	return 0;
}
