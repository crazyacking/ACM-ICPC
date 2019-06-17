#include <bits/stdc++.h>
using namespace std;

struct Request
{
	int arrival_time,need_time;
	Request(){};
	Request(int t1,int t2):arrival_time(t1),need_time(t2){};
	bool operator < (const Request& a)const
	{
		return (arrival_time<a.arrival_time) || (arrival_time==a.arrival_time && need_time<a.need_time);
	}
};

class Solution
{
public:
	double get_ave_wait_time(Request *requests,int n)
	{
		if(n<=0) return double(0.0);
		sort(requests,requests+n);
		// cout<<"--------------------"<<endl;
		// for(int i=0;i<n;++i)
		// {
		// 	cout<<requests[i].arrival_time<<" "<<requests[i].need_time<<endl;
		// }
		// cout<<"--------------------"<<endl;
		bool is_runned[n]={0};
		int next_run_p=0;
		int runned_num=1;
		int cur_time=0;
		int start_run_time[n];
		get_next_run_p(is_runned,requests,next_run_p,n);
		is_runned[next_run_p]=true;
		start_run_time[next_run_p]=requests[next_run_p].arrival_time;
		cur_time=requests[next_run_p].arrival_time + requests[next_run_p].need_time;
		while(runned_num<n)
		{
			get_next_run_p(is_runned,requests,next_run_p,n);
			start_run_time[next_run_p]=max(cur_time,requests[next_run_p].arrival_time);
			// cout<<cur_time<<" + "<<requests[next_run_p].need_time<<"="<<cur_time+requests[next_run_p].need_time<<endl;
			cur_time+=requests[next_run_p].need_time;
			is_runned[next_run_p]=true;
			++runned_num;
		}
		// cout<<"all of process's start run time:"<<endl;
		// for(int i=0;i<n;++i)
		// {
		// 	cout<<start_run_time[i]<<endl;
		// }
		// cout<<"====================="<<endl;

		double sum_wait_time=0;
		for(int i=0;i<n;++i)
			sum_wait_time+=start_run_time[i]-requests[i].arrival_time;
		return sum_wait_time/n;
	}

	void get_next_run_p(bool *is_runned,Request *requests,int &next_run_p,int n)
	{
		int shortest_run_time=INT_MAX;
		int earliest_arrival_time=INT_MAX;
		for(int i=0;i<n;++i)
		{
			if(!is_runned[i])
			{
				if(requests[i].arrival_time<=earliest_arrival_time && requests[i].need_time<shortest_run_time)
				{
					earliest_arrival_time=requests[i].arrival_time;
					shortest_run_time=requests[i].need_time;
					next_run_p=i;
				}
			}
		}
	}

};

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		Request requests[n];
		for(int i=0;i<n;++i)
		{
			cin>>requests[i].arrival_time>>requests[i].need_time;
		}
		Solution solution;
		double ave_wait_time=solution.get_ave_wait_time(requests,n);
		printf("%.4f\n",ave_wait_time);
	}
	return 0;
}
/*
4
4
1 4
1 3
1 5
2 1
-------------
5.2500

*/