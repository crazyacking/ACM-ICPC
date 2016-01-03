#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>pr,in;

void reBuild(int a,int b,int n,bool flag)
{
    if(n==1) // leaf node
    {
        cout<<pr[a]<<" ";
        return ;
    }
    else if(n<=0) // hasn't node
        return ;
    int i;
    for(i=0; pr[a]!=in[b+i]; ++i);
    reBuild(a+1,b,i,0);
    reBuild(a+1+i,b+i+1,n-i-1,0);
    if(flag) // root node
        cout<<pr[a];
    else // not root node
        cout<<pr[a]<<" ";
}

int main()
{
    while(cin>>n)
    {
        pr.clear();
        in.clear();
        for(int i=0; i<n; ++i)
        {
            int tmp;
            cin>>tmp;
            pr.push_back(tmp);
        }
        for(int i=0; i<n; ++i)
        {
            int tmp;
            cin>>tmp;
            in.push_back(tmp);
        }
        reBuild(0,0,n,true);
        cout<<endl;
    }
    return 0;
}
