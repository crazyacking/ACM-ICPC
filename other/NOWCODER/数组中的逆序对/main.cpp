#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
	int inversePairs(vector<int> data)
	{

	}
};

int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n)
	{
		vector<int> nums;
		for(int i=0;i<n;++i)
		{
			cin>>nums[i];
		}
		Solution solution;
		int ans=solution.inversePairs(nums);
		cout<<ans<<endl;
	}
	return 0;
}