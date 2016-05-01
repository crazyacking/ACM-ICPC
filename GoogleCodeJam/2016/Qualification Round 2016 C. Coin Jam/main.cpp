#include <bits/stdc++.h>
using namespace std;

const int NN=10000010;
bool v[NN];
int p[NN];
void makePrime()
{
    int num=-1,i,j;
    for(i=2; i<NN; ++i)
    {
        if(!v[i])
        {
            p[++num]=i;
        }
        for(j=0; j<=num && i*p[j]<NN; ++j)
        {
            v[i*p[j]]=true;
            if(i%p[j]==0)
            {
                break;
            }
        }
    }
    cout<<num<<endl;
}

class Solution
{
public:
    void solve(int N,int J)
    {
        long long low=pow(2,N),high=pow(2,N+1)-1;
        long long num;
        vector<int> nums(15);
        for(long long i=low; i<=high; ++i)
        {
            if(i&1)
            {
                nums[2]=2;
                for(int j=3; j<=10; ++j)
                {
                    num=change_base(i,j);
                    for(int p=0;p<664578;++p)
                    {

                    }
                }
            }
        }
    }

    long long change_base(long long n,int base)
    {
        string str;
        while(n)
        {
            if(n&1)
                str+='1';
            else
                str+='0';
            n>>=1;
        }
        long long res=0,b=1;
        for(int i=0; i<str.length(); ++i)
        {
            if(str[i]-'0'>0)
                res+=(str[i]-'0')*b;
            b*=base;
        }
        return res;
    }

};


int main()
{
    makePrime();
    int T;
    cin>>T;
    for(int Cas=1; Cas<=T; ++Cas)
    {
        int N,J;
        cin>>N>>J;

    }
    return 0;
}
