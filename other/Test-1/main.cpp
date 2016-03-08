#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1010
using namespace std;
int parents[110];
typedef struct node
{
    int a,b;
    int c;
} NODE;
NODE edges[6000];
bool cmp(NODE x,NODE y)
{
    if(x.c<y.c)
        return 1;
    return 0;
}

int find(int x)
{
    return x!=parents[x]?parents[x]=find(parents[x]):x;
}

int kruskal(int m)
{
    int i,mincost=0,x,y;
    for(i=0; i<m; i++)
    {
        x=edges[i].a;
        y=edges[i].b;
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            parents[x]=y;
            mincost+=edges[i].c;
        }
    }
    return mincost;
}
int main()
{
    int n,m,i,mincost=0;
    while(scanf("%d %d",&n,&m)!=EOF&&n!=0)
    {
        for(i=0; i<n; i++)
            scanf("%d %d %d",&edges[i].a,&edges[i].b,&edges[i].c);
        for(i=0; i<m; i++)
            parents[i]=i;
        sort(edges,edges+n,cmp);
        mincost=kruskal(n);
        int count=0;
        for(i=0; i<m; i++)
        {
            if(parents[i]==i)
                count++;
        }
        if(count>1) puts("?");
        else printf("%d\n",mincost);
    }
    return 0;
}
