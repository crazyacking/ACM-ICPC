#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	int inversePairs(vector<int> data)
	{
		merge_sort(data, 0, data.size() - 1);
	}

	void merge_sort(vector<int> &nums, int l, int r)
	{
		int mid = (l + r) >> 1;
		vector<int> vl = merge_sort(nums, l, mid);
		vector<int> vr = merge_sort(nums, mid + 1, r);
		return merge(vl, vr);
	}

	vector<int> merge(vector<int> vl, vector<int> vr)
	{
		int n1 = vl.size(), n2 = vr.size();
		vector<int> res(n1 + n2);
		int i = 0, j = 0;
		while (i < n1 && j < n2)
		{
			if (nums[i] < nums[j])
				res[cnt++] = nums[i++];
			else
				res[cnt++] = nums[j++];
		}
		while (i <n1)
			res[cnt++] = nums[i++];
		while (j <n2)
			res[cnt++] = nums[j++];
		return res;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		vector<int> nums;
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}
		Solution solution;
		int ans = solution.inversePairs(nums);
		cout << ans << endl;
	}
	return 0;
}