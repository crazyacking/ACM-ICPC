#include <bits/stdc++.h>
using namespace std;

const int MAXN=10010;

struct Edge
{
    int u,v,cost;
    bool operator<(const Edge &e)const
    {
        return cost<e.cost;
    }
};
int parent[MAXN];
int find(int x)
{
    return x==parent[x]?x:parent[x]=find(parent[x]);
}

vector<Edge> get_MST(vector<Edge> &edge,int &eNum,int &vNum)
{
    vector<Edge> res;
    for(int i=0;i<vNum;++i)
        parent[i]=i;
    int ansSet=0;
    long long minCost=0;
    for(int i=0;i<eNum;++i)
    {
        int x_pa=find(edge[i].u);
        int y_pa=find(edge[i].v);
        if(!i)
        {
            res.push_back(edge[i]);
            minCost+=edge[i].cost;
            parent[y_pa]=parent[x_pa];
            ansSet=parent[x_pa];
        }
        else
        {
            if(x_pa==y_pa && x_pa==ansSet)
                continue;
            res.push_back(edge[i]);
            minCost+=edge[i].cost;
            parent[x_pa]=parent[y_pa]=ansSet;
        }
    }
    cout<<"mini cost is:"<<minCost<<endl;
    return res;
}

void printMST(vector<Edge> mst)
{
    for(auto p:mst)
    {
        cout<<(p.u)<<" -----> "<<(p.v)<<" : "<<(p.cost)<<endl;
    }
}


int main()
{
    int vNum,eNum;
    while(cin>>vNum>>eNum)
    {
        vector<Edge> edge(eNum);
        for(int i=0;i<eNum;++i)
        {
            cin>>edge[i].u>>edge[i].v>>edge[i].cost;
        }
        sort(edge.begin(),edge.end());
        vector<Edge> res=get_MST(edge,eNum,vNum);
        printMST(res);
        cout<<"-----------------------------"<<endl;
    }
}
