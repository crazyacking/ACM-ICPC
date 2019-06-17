#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
	int InversePairs(vector<int> data)
	{
		ans = 0;
		merge_sort(data, 0, data.size() - 1);
		return ans;
	}

	vector<int> merge(vector<int> &vl, vector<int> &vr)
	{
		int n1 = vl.size(), n2 = vr.size();
		vector<int> res(n1 + n2);
		int i = 0, j = 0, cnt = 0;
		while (i < n1 && j < n2)
		{
			if (vl[i]  <= vr[j])
				res[cnt++] = vl[i++];
			else
			{
				ans += n1 - i;/* 统计答案 */
				res[cnt++] = vr[j++];
			}
		}
		while (i < n1)
			res[cnt++] = vl[i++];
		while (j < n2)
			res[cnt++] = vr[j++];
		return res;
	}

	vector<int> merge_sort(vector<int> &nums, int l, int r)
	{
		vector<int> vl, vr;
		if (l < r)
		{
			int mid = (l + r) >> 1;
			vl = merge_sort(nums, l, mid);
			vr = merge_sort(nums, mid + 1, r);
			return merge(vl, vr);
		}
		else
		{
			vector<int> ve(r - l + 1);
			int cnt = 0;
			for (int i = l; i <= r; ++i)
				ve[cnt++] = nums[i];
			return ve;
		}
	}
private:
	int ans;
};

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
			cin >> nums[i];
		Solution solution;
		int ans = solution.inversePairs(nums);
		cout << ans << endl;
	}
	return 0;
}