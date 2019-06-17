#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int    MAXE = 10000,
             MAXN = 10000,
             INF  = 1000000000;
int e, n, a, b, c;

int head[MAXN],     //����ʼλ��
    v[MAXE],        //�ߵ��յ�
    next[MAXE],     //��һ���ߵ�ַ
    w[MAXE],        //Ȩֵ
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
        next[i] = head[b];    //ָ��ͬ������һ����
        head[b] = i;          //����bָ������һ����λ��
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
