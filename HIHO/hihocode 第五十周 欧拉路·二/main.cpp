#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>

#define MEM(a,x) memset(a,x,sizeof a)
#define eps 1e-8
#define MOD 10009
#define MAXN 5010
#define MAXM 100010
#define INF 99999999
#define ll __int64
#define bug cout<<"here"<<endl
#define fread freopen("ceshi.txt","r",stdin)
#define fwrite freopen("out.txt","w",stdout)

using namespace std;

int Read()
{
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    int x = 0;
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

void Print(int a)
{
     if(a>9)
         Print(a/10);
     putchar(a%10+'0');
}

struct Stack
{
    int top,node[MAXN];
}s;
int Edge[MAXN][MAXN];
int n;
void dfs(int x)
{
    s.top++;
    s.node[s.top]=x;
    for(int i=0;i<n;i++)
    {
        if(Edge[i][x]>0)
        {
//            Edge[i][x]=0; Edge[x][i]=0; //删除此边
            Edge[i][x]--; Edge[x][i]--;//删除此边 数量减一
            dfs(i);
            break;
        }
    }
}

void Fleury(int x)
{
    int i,b;
    s.top=0; s.node[s.top]=x;
    int flag=0;
    while(s.top>=0)
    {
        b=0;
        for(i=0;i<n;i++)
        {
            if(Edge[s.node[s.top]][i]>0)
            {
                b=1; break;
            }
        }
        if(b==0)
        {
            if(flag) printf(" ");
            flag=1;
            printf("%d",s.node[s.top]+1);
            s.top--;
        }
        else
        {
            s.top--;
            dfs(s.node[s.top+1]);
        }
    }
    puts("");
}

int main()
{
//    fread;
    int m;
//    scanf("%d%d",&n,&m);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int deg,num,start;
        MEM(Edge,0);
        for(int i=0;i<m;i++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            Edge[s-1][t-1]++;
            Edge[t-1][s-1]++;    //数据中有重边  将标记改为边的数量
        }
        num=0; start=0;
        for(int i=0;i<n;i++)
        {
            deg=0;
            for(int j=0;j<n;j++)
                deg+=Edge[i][j];
            if(deg%2==1)
            {
                start=i;
                num++;
            }
        }
        if(num==0||num==2)
            Fleury(start);
//        else puts("");
    }
    return 0;
}
