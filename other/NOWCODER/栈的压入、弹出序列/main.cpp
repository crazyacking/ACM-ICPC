#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		int n=pushV.size();
		if(!n || n!=popV.size())
			return false;
		vector<int> sta;
		int j=0;
		for(int i=0;i<n;++i)
		{
			sta.push_back(pushV[i]);
			while(sta.size()>0 && sta[sta.size()-1]==popV[j])
				sta.pop_back(),j++;
		}
		if(j==n)
			return true;
		return false;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	while(cin>>n)
	{
		vector<int> pushV(n),popV(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>pushV[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>popV[i];
		}
		Solution solution;
		bool ans=solution.IsPopOrder(pushV,popV);
		if(ans)
			cout<<"Yes."<<endl;
		else
			cout<<"No."<<endl;
	}
	return 0;
}