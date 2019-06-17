#include <bits/stdc++.h>
using namespace std;

int _gcd(int a,int b)
{
	return b?_gcd(b,a%b):a;
}
int _lcm(int a,int b)
{
	return a*b/_gcd(a,b);
}
/*
gcd：最小公倍数，至少需要gcd匹马（马匹总数，包括牵来的）
sum：最少的分配总和，即：至少需要分配sum匹马给son们
*/
int main()
{
	int horse,son;
	while(cin>>horse>>son,horse+son)
	{
		vector<int> ratio(son);
		int lcm=1,sum=0;
		for(int i=0;i<son;++i)
		{
			cin>>ratio[i];
			lcm=_lcm(lcm,ratio[i]);
		}
//		cout<<"lcm="<<lcm<<endl;
		for(int i=0;i<son;++i)
			sum+=lcm/ratio[i];
		if(horse%sum)
			cout<<"Can't Solve"<<endl;
		else
		{
			/* 分配horse/sum轮，每轮分配lcm/ratio[i]匹马给第i个儿子 */
			for(int i=0;i<son;++i)
                printf(i==son-1?"%d\n":"%d ",(horse/sum)*(lcm/ratio[i]));
		}
	}
	return 0;
}
