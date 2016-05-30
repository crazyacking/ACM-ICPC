#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,b;
    while(cin>>n>>b)
    {
        int t=n/b;
        if(abs((t+1)*b-n)<=abs(t*b-n)) ++t;
        cout<<t*b<<endl;
    }
    return 0;
}
