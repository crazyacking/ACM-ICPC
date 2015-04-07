#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const LL MOD=10007;

LL N;
LL POW(LL x)
{
        if(x==0) return 1LL;
        if(x%2==0) return (POW(x/2)*POW(x/2))%MOD;
        return (2LL*POW(x-1))%MOD;
}
int main()
{
        int test;
        cin>>test;
        for(int i=0;i<=test;++i)
        {
                cin>>N;
                cout<<(POW(N)+(POW(N-1)-1)*POW(N-1))%MOD<<endl;
        }
        return 0;
}
