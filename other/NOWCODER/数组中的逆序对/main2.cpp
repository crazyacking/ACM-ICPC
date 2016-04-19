#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> &nums, int l, int mid, int r)
{
	vector<int> tmp_arr(r - l + 1);
	int i = l, j = mid + 1, cnt = 0;
	while (i <= mid && j <= r)
	{
		if (nums[i] < nums[j])
			tmp_arr[cnt++] = nums[i++];
		else
			tmp_arr[cnt++] = nums[j++];
	}
	while (i <= mid)
	{
		tmp_arr[cnt++] = nums[i++];
	}
	while (j <= r)
	{
		tmp_arr[cnt++] = nums[j++];
	}
	for (int i = 0; i < r - l + 1; ++i)
	{
		nums[i] = tmp_arr[i];
	}
}


int main(int argc, char const *argv[])
{
	int n;
	while(cin>>n)
	{
		vector<int> nums(n);
		for(int i=0;i<n;++i)
		{
			cin>>nums[i];
		}
		int mid=(0+n-1)>>1;
		merge(nums,0,mid,n-1);
		for(int i=0;i<n;++i)
			cout<<nums[i]<<" ";
		cout<<endl;
	}
	return 0;
}