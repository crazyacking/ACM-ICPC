#include <bits/stdc++.h>
using namespace std;

const int MAXM=666666;
int n,m,s,d;
int dis[MAXM],cost[MAXM];

class Solution
{
public:
    void work(vector<vector<pair<int,pair<int,int> > > > &graph)
    {
        unordered_set<int> s1;
        bool in_s1[MAXM];
        memset(in_s1,0,sizeof(in_s1));
        unordered_map<int,int> pre;
        for(int i=0;i<MAXM;++i)
            dis[i]=cost[i]=0x3f3f3f3f;
        dis[s]=cost[s]=0;
        s1.insert(s);
        in_s1[s]=1;
        while((int)s1.size()<n)
        {
            int select=-1,pr;
            int min_dis,min_cost;
            min_dis=min_cost=0x3f3f3f3f;
            unordered_set<int>::iterator it;
            for(it=s1.begin();it!=s1.end();++it)
            {
                int pos1=(*it);
                for(int i=0;i<(int)graph[pos1].size();++i)
                {
                    int pos2=graph[pos1][i].first;
                    int d=(graph[pos1][i].second).first;
                    int c=(graph[pos1][i].second).second;
                    if(!in_s1[pos2])
                    {
                        if(dis[pos1]+d<min_dis || (dis[pos1]+d==min_dis && cost[pos1]+c<min_cost))
                        {
                            min_dis=dis[pos1]+d;
                            min_cost=cost[pos1]+c;
                            select=pos2;
                            pr=pos1;
                        }
                    }
                }
            }
            if(select==-1)
            {
                puts("0 0 0 0");// can't reach
                return;
            }
            s1.insert(select);
            in_s1[select]=1;
            dis[select]=min_dis;
            cost[select]=min_cost;
            pre[select]=pr;
            if(select==d)
                break;
        }

        vector<int> path;
        path.push_back(d);
        int p=pre[d];
        while(p!=s)
        {
            path.push_back(p);
            p=pre[p];
        }
        path.push_back(s);
        for(int i=path.size()-1;i>=0;--i)
            cout<<path[i]<<" ";
        cout<<dis[d]<<" "<<cost[d]<<endl;
    }
};


int main()
{
    while(cin>>n>>m>>s>>d)
    {
        vector<vector<pair<int,pair<int,int> > > > graph(n);
        int pos1,pos2,dis,cost;
        for(int i=0;i<m;++i)
        {
            cin>>pos1>>pos2>>dis>>cost;
            graph[pos1].push_back(make_pair(pos2,make_pair(dis,cost)));
            graph[pos2].push_back(make_pair(pos1,make_pair(dis,cost)));
        }
        Solution solution;
        solution.work(graph);
    }
    return 0;
}

/**<
===============================================================
8 8 0 7
0 1 3 6
1 2 4 7
2 3 2 1
3 4 6 4
4 5 7 3
5 6 9 2
6 7 11 8
1 3 5 37


8 8 0 7
0 1 3 6
1 2 4 7
2 3 2 1
3 4 6 4
4 5 7 3
5 6 9 2
6 7 11 8
1 4 5 37


8 8 0 7
0 1 3 6
1 2 4 7
2 3 6 1
3 4 6 4
4 5 7 8
5 6 9 2
6 7 11 8
1 4 56 37


9 10 1 8
0 1 3 1
1 2 4 3
3 2 1 2
3 4 7 6
2 5 10 7
1 3 8 9
5 6 6 10
7 6 1 1
5 8 1 86
7 8 9 2


9 10 1 8
0 1 3 1
1 2 4 3
3 2 1 2
3 4 7 56
2 5 2 7
1 3 1 78
5 6 8 10
7 6 1 2
5 8 1 6
7 8 9 9


9 10 1 8
0 1 6 1
1 2 45 63
3 2 1 82
3 4 8 56
2 5 6 125
1 3 78 78
5 6 23 10
7 6 68 62
5 8 1 23
7 8 9 22



 */
