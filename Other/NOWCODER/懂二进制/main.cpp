#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     * 
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {
    	int res=0;
    	while(m&&n){
    		if((m&1)!=(n&1))
    			++res;
    		m>>=1,n>>=1;
    	}
    	while(n)
    	{
    		if((n&1))
    			++res;
    		n>>=1;
    	}
    	while(m)
    	{
    		if((m&1))
    			++res;
    		m>>=1;
    	}
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n>>m)
	{
		Solution solution;
		int ans=solution.countBitDiff(n,m);
		cout<<ans<<endl;
	}
	return 0;
}