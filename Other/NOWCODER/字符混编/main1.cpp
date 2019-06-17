#include "bits/stdc++.h"


// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
using namespace std;
float waitingTimeSJF(int *requestTimes, int *durations, int n)
{
	if (n <= 0)
		return (float)(0.0);
	// WRITE YOUR CODE HERE
	bool is_runned[n];
	memset(is_runned, 0, sizeof(is_runned));
	int start_run_time[n];
	int first_run_p = 0;
	int min_run_time = 1000000;
	for (int i = 0; i < n; ++i)
	{
		if (requestTimes[i] == requestTimes[0])
		{
			if (durations[i] < min_run_time)
			{
				min_run_time = durations[i];
				first_run_p = i;
			}
		}
		else break;
	}


	int cur_time = durations[first_run_p];
	is_runned[first_run_p] = true;

	for (int j = 0; j < n; ++j)
	{
		bool is_find=0;
		int min_run_time = 1000000;
		for (int i = 0; i < n; ++i)
		{
			if (cur_time >= requestTimes[i] && is_runned[i] == false)
			{
				if (durations[i] > min_run_time)
				{
					min_run_time = durations[i];
					first_run_p = i;
					is_find=1;
				}
			}
		}
		if(!is_find)
		{
			int zui_zao_shi_jian=1000000;
			int zui_shao_yun_xing=1000000;
			for(int i=0;i<n;++i)
			{
				if(is_runned[i]==false)
				{
					if(requestTimes[i]<=zui_zao_shi_jian)
					{
						zui_zao_shi_jian=requestTimes[i];
						if(durations[i]<zui_shao_yun_xing)
						{
							zui_shao_yun_xing=durations[i];
							first_run_p=i;
						}
					}
				}
			}
			cur_time=requestTimes[first_run_p];
		}
		start_run_time[first_run_p] = cur_time;
		is_runned[first_run_p]=true;
		cur_time += durations[first_run_p];
	}

	double sum_of_wait_time=0.0;
	for(int i=0;i<n;++i)
	{
		sum_of_wait_time+=abs(requestTimes[i]-start_run_time[i]);
	}

	return sum_of_wait_time/(n*1.0);
}
// FUNCTION SIGNATURE ENDS
int main()
{
//    freopen("G:\\nowcoder\\1.in","r",stdin);
//    freopen("G:\\nowcoder\\1.out","w",stdout);
    
    return 0;
}
/*

*/