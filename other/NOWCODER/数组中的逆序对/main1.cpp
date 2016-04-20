#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &vl, vector<int> &vr)
{
	int n1 = vl.size(), n2 = vr.size();
	vector<int> res(n1 + n2);
	int i = 0, j = 0, cnt = 0;
	while (i < n1 && j < n2)
	{
		if (vl[i] < vr[j])
			res[cnt++] = vl[i++];
		else
			res[cnt++] = vr[j++];
	}
	while (i < n1)
		res[cnt++] = vl[i++];
	while (j < n2)
		res[cnt++] = vr[j++];
	return res;
}

vector<int> merge_sort(vector<int> &nums, int l, int r)
{
	vector<int> vl,vr;
	if (l < r)
	{
		int mid = (l + r) >> 1;
		vl = merge_sort(nums, l, mid);
		vr = merge_sort(nums, mid + 1, r);
		return merge(vl, vr);
	}
	else
	{
		vector<int> ve(r-l+1);
		int cnt=0;
		for(int i=l;i<=r;++i)
			ve[cnt++]=nums[i];
		return ve;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	while (cin >> n)
	{
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> nums[i];
		}
		nums=merge_sort(nums, 0, n - 1);
		for (int i = 0; i < nums.size(); ++i)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	return 0;
}