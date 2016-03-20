#include <bits/stdc++.h>
using namespace std;

int NumberOf1(int x)
{
    int res=0;
    while(x)
    {
        ++res;
        x=(x-1)&x;
    }
    return res;
}

int main()
{
    int n;
    while(cin>>n)
    {
        cout<<NumberOf1(n)<<endl;
    }
    return 0;
}
