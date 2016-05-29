#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)  // a/b
    {
        if(a==1 || b%a==0)
        {
            cout<<a<<"/"<<b<<endl;
            continue;
        }
        bool f=0;
        int j=b;
        vector<int> ans;
        while(1)
        {
            int c=b/a+1; // 1/c
            if(c>100000000 || c<0)
            {
                f=1;
                break;
            }
            if(c==j)
                ++c;
            ans.push_back(c);
            a=a*c-b;
            b=b*c;

            // hua jian a/b
            for(int u=2;u<=a;++u)
                while(a%u==0 && b%u==0)
                    a/=u,b/=u;

            if(a==1 && b!=j)
            {
                ans.push_back(b);
                break;
            }
        }
        if(f) puts("NOT FIND");
        else
        {
            for(auto p:ans)
                cout<<p<<" ";
            cout<<endl;
        }
    }
    return 0;
}
