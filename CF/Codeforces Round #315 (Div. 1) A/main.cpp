#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;
const int N=100010;
int n;
int s[N*2];
int P[N*2];


int cal(int len)
{
    if(n<3) return 0;
    int id=1, mx=1;
    P[0]=1;
    P[1]=1;
    for(int i=2; i<len; i++)
    {
        P[i] =i>mx? 1: min( P[2*id-i], mx-i);
        while(s[i+P[i]]==s[i-P[i]])    P[i]++;
        if(i+P[i]>mx)
        {
            id=i;
            mx=i+P[i];
        }
    }
    int ans=0;
    for(int i=3; i+4<len; i+=2)
    {
        int tag=P[i]-1;
        if( tag>1 && tag>ans )
        {
            while( P[i+tag]<=tag && tag>ans )    tag--;
            if(tag>ans) ans=tag;
        }
    }

    return ans/2*3;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t, tmp, j=0;
    cin>>t;

    while(t--)
    {
        scanf("%d", &n);
        s[0]=-1;
        s[1]=-2;
        for(int i=0,j=2; i<n; i++)
        {
            scanf("%d",&tmp);
            s[j++]=tmp;
            s[j++]=-2;
        }
        s[n*2+2]=-30;

        printf("Case #%d: %d\n", ++j, cal( n*2+2 ));
    }
    return 0;
}
