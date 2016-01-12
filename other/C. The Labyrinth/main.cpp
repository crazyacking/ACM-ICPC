/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-12-00.04
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int MAXN=1010;
char MP[MAXN][MAXN];
int dx[]= {1,0,-1,0};
int dy[]= {0,1,0,-1};


void Search(int x,int y,int cnt)
{
    for(int i=0; i<4; ++i)
        if(MP[x+dx[i]][y+dy[i]]=='.'||MP[x+dx[i]][y+dy[i]]=='@')
        {
            MP[x+dx[i]][y+dy[i]]='@';
            Search(x+dx[i],y+dy[i],++cnt);
            MP[x+dx[i]][y+dy[i]]=='.';
        }
}
bool vis[MAXN][MAXN];
void initializer()
{
    memset(vis,0,sizeof vis);
}
int n,m;
bool OUT(int x,int y)
{
    return ((x < 0)||(y < 0) || (x >= n) || (y >= m));
}

int st[5];
int c[MAXN][MAXN];
int cnt[MAXN * MAXN],TMP = 0;
char CNT(int x,int y)
{
    int ct=1;
    int numx,numy;
    int k = 0;
    if(MP[x][y] == '.')
        return MP[x][y];
    for(int i =0; i< 4; i++)
    {
        numx = x + dx[i];
        numy = y + dy[i];
        if(OUT(numx,numy) || MP[numx][numy] == '*') continue;
        st[++k] = c[numx][numy];
    }
    for(int i = 1;i<= k; i++)
    {
        ct =ct +  cnt[st[i]];
        for(int j = 1; j < i; ++j)
            if(st[j] == st[i])
            {
                ct = ct- cnt[st[i]];
                break;
            }
    }
    return (ct % 10) + '0';
}
void Search(int x,int y)
{
    if(vis[x][y] || MP[x][y] == '*')return;
    vis[x][y] = true;
    c[x][y] = TMP;
    ++cnt[TMP];
    for(int i = 0; i < 4; i++)
        if(!OUT(x + dx[i],y + dy[i]))
            Search(x + dx[i],y + dy[i]);
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; ++i)
        scanf("%s",MP[i]);
    initializer();
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(MP[i][j]!='*' && (!vis[i][j]))
            {
                TMP++;
                cnt[TMP]=0;
                Search(i,j);
            }
        }
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            MP[i][j]=CNT(i,j);
        }
    }
    for(int i=0; i<n; ++i)
        printf("%s\n",MP[i]);
    return 0;
}
