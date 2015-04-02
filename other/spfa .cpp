#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int    MAXE = 10000,
             MAXN = 10000,
             INF  = 1000000000;
int e, n, a, b, c;

int head[MAXN],     //存起始位置
    v[MAXE],        //边的终点
    next[MAXE],     //下一条边地址
    w[MAXE],        //权值
    d[MAXN];

queue<int> q;
bool vis[MAXN];
void spfa(int root)
{
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) d[i] = INF;
    d[root] = 0;
    q.push(root);
    int t, i;
    while(!q.empty())
    {
        t = q.front(); q.pop();
        i = head[t];
        while(i)
        {
            if(d[v[i]] > d[t]+w[i])
            {
                d[v[i]] = d[t] + w[i];
                if(!vis[v[i]])
                {
                    vis[v[i]] = 1;
                    q.push(v[i]);
                }
            }
            i = next[i];
        }
        vis[t] = 0;
    }

}

int main()
{
    cin >> n >> e;
    for(int i = 1; i <= e; i++)
    {
        cin >> b >> v[i] >> w[i];
        next[i] = head[b];    //指向同起点的上一条边
        head[b] = i;          //更新b指向的最后一条边位置
    }
    cin >> a;
    for(int i = 0; i < a; i++)
    {
        cin >> b >> c;
        spfa(b);
        if(d[c] == INF) cout << "No Answer!\n";
        else cout << d[c] << endl;
    }
    return 0;
}
