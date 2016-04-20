#include <bits/stdc++.h>
using namespace std;


vector<int> merge(vector<int> vl, vector<int> vr)
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


int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n>>m)
	{
		vector<int> v1(n);
		vector<int> v2(m);
		for(int i=0;i<n;++i)
		{
			cin>>v1[i];
		}
		for(int i=0;i<m;++i)
		{
			cin>>v2[i];
		}
		vector<int> res=merge(v1,v2);
		for(int i=0;i<res.size();++i)
			cout<<res[i]<<" ";
		cout<<endl;
	}
	return 0;
}