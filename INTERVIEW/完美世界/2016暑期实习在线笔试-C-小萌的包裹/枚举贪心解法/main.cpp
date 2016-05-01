#include <bits/stdc++.h>
using namespace std;

const int MAXN=25;
int N,T,M;
int v[MAXN];

int main(int argc, char const *argv[])
{
	while(~scanf("%d %d %d",&N,&T,&M))
	{
		for(int i=0;i<N;++i)
			scanf("%d",&v[i]);
		unsigned int high=pow(2,N+1)-1,cur,package,cur_v,idx;
		int ans=0,cnt;
		for(int low=0;low<=high;++low)
		{
			cur=low,cnt=0;
			package=0,cur_v=0,idx=0;
			while(cur)
			{
				if(cur&1)
				{
					++cnt;
					if(cur_v+v[idx]<=T)
						cur_v+=v[idx];
					else
					{
						++package;
						cur_v=0;
					}
				}
				if(package>M)
					break;
				cur>>=1;
				++idx;
			}
			if(package<=M)
				ans=max(ans,cnt);
			cout<<"ldsf"<<endl;
		}
		printf("run here~");
		printf("%d\n",ans);
	}
	return 0;
}