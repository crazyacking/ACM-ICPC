#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
int m,n,a,b,T;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int vis[10][10];
char map[10][10];
int c,d;
int dfs(int x,int y,int now)
{
    int i,xx,yy;
    if(now==T)
    {
        if(map[x][y]=='D')
            return 1;
        else
            return 0;
    }
    if((T-now+c-x+d-y)%2)
        return 0;
    for(i=0;i<4;++i)
    {
        xx=x+dx[i];
        yy=y+dy[i];
        if(xx<0|| xx>=m || yy<0 || yy>=n || vis[xx][yy] || map[xx][yy]=='X')
            continue;
        vis[xx][yy]=1;
        if(dfs(xx,yy,now+1))
            return 1;
        vis[xx][yy]=0;
    }
    return 0;
}
int main()
{
    int i,j;
    while(scanf("%d%d%d",&m,&n,&T)!=EOF && m)
    {
        scanf("%*c");
        for(i=0;i<m;++i)
        {
            scanf("%s",map[i]);
            for(j=0;j<n;++j)
            {    if(map[i][j]=='S')
                {
                    a=i;
                    b=j;
                }
            else if(map[i][j]=='D')
            {
                c=i;
                d=j;
            }
            }
        }
        memset(vis,0,sizeof(vis));
        vis[a][b]=1;
        printf("%s\n",dfs(a,b,0)?"YES":"NO");
    }
    return 0;
}
