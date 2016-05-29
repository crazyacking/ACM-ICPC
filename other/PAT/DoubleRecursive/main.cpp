#include <bits/stdc++.h>
using namespace std;

const int MAXN=100010;
int m[MAXN];

int get_nth(int n)
{
    int p2=1,p5=1;
    m[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(2*m[p2]+1 < 5*m[p5]-1)
        {
            m[i]=2*m[p2]+1;
            ++p2;
        }
        else if(2*m[p2]+1 > 5*m[p5]-1)
        {
            m[i]=5*m[p5]-1;
            ++p5;
        }
        else
        {
            ++p2,++p5;
            m[i]=5*m[p5]-1;
        }
    }
    return m[n];
}

int main()
{
    int n;
    while(cin>>n)
    {
        int ans=get_nth(n);
        cout<<ans<<endl;
    }
    return 0;
}
