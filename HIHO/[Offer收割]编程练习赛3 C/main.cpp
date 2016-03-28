#include <bits/stdc++.h>
using namespace std;

const int MAXN=1010;
int N,M,S,T;
int A[MAXN];

int cha=0;

bool flag;

bool work(int guan,int jihui,int dui)
{
    if(guan>=N)
    {
        cout<<dui<<endl;
        flag=1;
        return true;
    }
    for(int i=0;i<=jihui;++i) // 答对多少道
    {
        cha=A[guan]-i*S;
        int dacuo=0;

        if(cha%T==0)
            dacuo=cha/T;
        else
            dacuo=cha/T+1;
        if(dacuo+i>jihui)
            continue;
        else
        {
            if(work(guan+1,jihui-dacuo-i,dui+i))
                return true;
        }
    }
    return false;
}

int main()
{
    int cas;
    cin>>cas;
    while(cas--)
    {
        flag=0;
        cin>>N>>M>>S>>T;
        for(int i=0;i<N;++i)
            cin>>A[i];
        if(!work(0,M,0))
            cout<<"No"<<endl;
    }
    return 0;
}

