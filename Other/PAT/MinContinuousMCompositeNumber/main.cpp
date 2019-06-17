#include <bits/stdc++.h>
using namespace std;


bool check(int x)
{
    for(int i=2;i<=(int)(sqrt(x));++i)
        if(x%i==0)
            return 1;
    return 0;
}

void solve(int m)
{
    int i=4,start=3;
    while(1)
    {
        if(check(i))
        {
            if(i-start>=m)
            {
                printf("%d,%d\n",start+1,i);
                break;
            }
        }
        else start=i;
        ++i;
    }
}

int main()
{
    int m;
    while(cin>>m)
    {
        solve(m);
    }
    return 0;
}
