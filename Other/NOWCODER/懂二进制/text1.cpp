#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n>>m)
	{
		char s1[100],s2[100];
		memset(s1,'\0',sizeof s1);
		memset(s2,'\0',sizeof s2);
		itoa(n,s1,2);
		itoa(m,s2,2);
		int l1=strlen(s1),l2=strlen(s2);
		if(l1>l2)
			swap(s1,s2);
		for(int i=0;i<l2-l1;++i)
			printf("0");
		puts(s1);
		puts(s2);
	}
	return 0;
}