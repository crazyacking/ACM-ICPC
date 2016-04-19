#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		set<int> se;
		int cnt=0;
		set<int> ans;
		for(int i=0;i<length;++i)
		{
			if(se.count(numbers[i])==0)
			{
				se.insert(numbers[i]);
			}
			else
			{
				if(ans.count(numbers[i])==0)
				{
					duplication[cnt++]=numbers[i];
					ans.insert(numbers[i]);
				}
			}
		}
		if(!cnt)
			return false;
		return true;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		int nums[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}
		int len = n;
		int res[n];
		fill(res,res+n,-1);
		Solution solution;
		solution.duplicate(nums,n,res);
		for(int i=0;i<n;++i)
		{
			if(res[i]!=-1)
			{
				cout<<res[i]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}