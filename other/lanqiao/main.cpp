#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,m;
	while(cin>>n>>m) 
	{
		long long a=(long long)sqrt(n);
		long long b=(long long)sqrt(m);
		cout<<a*b<<endl;
	}
	return 0;
}
