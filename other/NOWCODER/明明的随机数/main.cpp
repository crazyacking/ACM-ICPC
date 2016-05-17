#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        set<int> se;
        for(int i=0;i<n;++i)
        {
            int val;
            cin>>val;
            se.insert(val);
        }
        set<int>::iterator it;
        for(it=se.begin();it!=se.end();++it)
        {
            cout<<(*it)<<endl;
        }
    }
    return 0;
}
