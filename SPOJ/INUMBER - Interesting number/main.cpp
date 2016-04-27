#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while (T--)
	{
		
		long long n;
		vector<long long> nums(n);
		for (int i = 0; i < n; ++i)
			cin >> nums[i];
		sort(nums.begin(), nums.end());
		long long cnt_max = 0, cnt_min = 0;
		if (nums[0] == nums[n - 1])
			cnt_min = cnt_max = (n) * (n - 1) / 2;
		else
		{
			long long front = nums[0], back = nums[n - 1];
			long long cnt_front = 1, cnt_back = 1;
			for (int i = 1; i < n; ++i)
			{
				if (nums[i] == front)
					++cnt_front;
				else break;
			}
			for (int i = n - 2; i >= 0; --i)
			{
				if (nums[i] == back)
					++cnt_back;
				else break;
			}
			cnt_max = cnt_front * cnt_back;
			//
			long long min_dif = LLONG_MAX;
			for (int i = 0; i < n - 1; ++i)
				min_dif = min(min_dif, nums[i + 1] - nums[i]);
			if (!min_dif)
			{
				long long cnt = 1, tmp = nums[0];
				for (int i = 1; i < n; ++i)
				{
					if (nums[i] == tmp)
						++cnt;
					else
					{
						cnt_min += (cnt - 1) * cnt / 2;
						tmp = nums[i];
						cnt = 1;
					}
				}
				cnt_min += (cnt - 1) * cnt / 2;
			}
			else
			{
				for (int i = 1; i < n; ++i)
					if (nums[i] - nums[i - 1] == min_dif)
						++cnt_min;
			}
		}
		cout << cnt_min << " " << cnt_max << endl;
	}
	return 0;
}
/*
1
6
45 12 45 32 5 6

*/