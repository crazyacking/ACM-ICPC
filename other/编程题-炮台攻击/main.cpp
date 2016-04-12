#include <bits/stdc++.h>
using namespace std;
const double eps=1e-8;

int x[4],y[4];

double get_dis(int idx)
{
    double p1=pow(x[idx]-x[3],2);
    double p2=pow(y[idx]-y[3],2);
    return sqrt(p1+p2);
}

int main()
{
    int r;
    while(cin>>r)
    {
        for(int i=0;i<4;++i)
        {
            cin>>x[i]>>y[i];
        }

        int ans=0;
        for(int i=0;i<3;++i)
        {
            if(get_dis(i)<=r)
                ans++;
        }
        cout<<ans<<"x"<<endl;
    }
    return 0;
}
