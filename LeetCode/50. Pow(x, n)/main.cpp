#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double n,int k)
    {
        double res;
        bool flag=0;
        if(n<0)
        {
        	flag=1;
        	n=fabs(n);
		}
		long long m=k;
		
		if(k<0)
		{
			n=1./n;
			m=abs(k);
		}
		double ans=1;
		double temp=1;
		while(m)
		{
			temp*=n;
			if(k&1)
				ans*=temp;
			
			m>>=1;
		}
		if(flag)
			ans=-1*ans;
		return ans;
    }
};

int main()
{
	double n,k;
	while(cin>>n>>k)
	{
		Solution solution;
		double ans=solution.myPow(n,k);
		cout<<ans<<endl;
	}
	
	return 0;
}
