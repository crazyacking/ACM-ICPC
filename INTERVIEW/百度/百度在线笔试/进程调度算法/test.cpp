#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	cout<<sizeof(int)<<endl;
	cout<<(1<<30)<<endl;
	cout<<(INT_MAX)<<endl;
	if((1<<16)-1==INT_MAX)
		cout<<"Yes."<<endl;
	else
		cout<<"No."<<endl;
	return 0;
}