#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int six_degreess_of_separation(vector<vector<int> > &mat,int p1,int p2)
	{
		--p1,--p2;
		int n=mat.size();
		bool vis[n][n];
		memset(vis,0,sizeof vis);
		queue<pair<int,int> > que;// di i ge ren he p1 de guan xi jian ge j
		que.push(make_pair(p1,0));
		while(!que.empty())
		{
			pair<int,int> cur=que.front();
			que.pop();
			int cur_person=cur.first;
			int gap=cur.second;
			if(mat[cur_person][p2])
				return gap;
			// cout<<"hehe1"<<endl;
			for(int i=0;i<n;++i)
			{
				if(!vis[cur_person][i] && mat[cur_person][i])
				{
					vis[cur_person][i]=true;
					que.push(make_pair(i,gap+1));
				}
			}
		}
		return -1;
	}
	
};

int main(int argc, char const *argv[])
{
	int Cas;
	cin>>Cas;
	while(Cas--)
	{
		int n;
		cin>>n;
		vector<vector<int> > mat(n,vector<int>(n));
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
				cin>>mat[i][j];
		}

		Solution solution;
		int q;
		cin>>q;
		while(q--)
		{
			int p1,p2;
			cin>>p1>>p2;
			int ans=solution.six_degreess_of_separation(mat,p1,p2);
			if(ans<0)
				cout<<"Sorry"<<endl;
			else
				cout<<ans<<endl;
		}
	}
	return 0;
}