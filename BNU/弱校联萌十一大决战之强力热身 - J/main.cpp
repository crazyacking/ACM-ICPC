#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
map<int,int>::iterator it;
struct point
{
      int x,y;
} in[1010];
struct Vis
{
      int x,y,dir;
      Vis() {}
      Vis(int x,int y,int dir)
      {
            this->x=x;
            this->y=y;
            this->dir=dir;
      }
      bool operator<(Vis a)const
      {
            return x!=a.x?x<a.x:y!=a.y?y<a.y:dir<a.dir;
      }
};
int main()
{
      int n;
      while(scanf("%d",&n)!=EOF)
      {
            map<int,int>hs;
            hs[0];
            for(int i=0; i<n; i++)
            {
                  scanf("%d%d",&in[i].x,&in[i].y);
                  hs[in[i].x];
                  hs[in[i].y];
            }
            int sum=0;
            for(it=hs.begin(); it!=hs.end(); it++)
                  it->second=sum++;
            set<int>::iterator jt;
            set<int>stx[2010],sty[2010];
            for(int i=0; i<n; i++)
            {
                  stx[hs[in[i].x]].insert(in[i].y);
                  sty[hs[in[i].y]].insert(in[i].x);
            }
            set<Vis>vis;
            Vis now=Vis(0,0,2);
            bool flag=0;
            sum=0;
            while(!flag)
            {
                  if(now.dir==1)
                  {
                        int id=hs[now.x];
                        jt=stx[id].upper_bound(now.y);
                        if(jt==stx[id].end())
                              flag=1;
                        else
                        {
                              now.y=*jt-1;
                              now.dir=2;
                              if(vis.count(now))
                                    break;
                              vis.insert(now);
                        }
                  }
                  else if(now.dir==2)
                  {
                        int id=hs[now.y];
                        jt=sty[id].upper_bound(now.x);
                        if(jt==sty[id].end())
                              flag=1;
                        else
                        {
                              now.x=*jt-1;
                              now.dir=3;
                              if(vis.count(now))
                                    break;
                              vis.insert(now);
                        }
                  }
                  else if(now.dir==3)
                  {
                        int id=hs[now.x];
                        jt=stx[id].lower_bound(now.y);
                        if(jt==stx[id].begin())
                              flag=1;
                        else
                        {
                              jt--;
                              now.y=*jt+1;
                              now.dir=4;
                              if(vis.count(now))
                                    break;
                              vis.insert(now);
                        }
                  }
                  else
                  {
                        int id=hs[now.y];
                        jt=sty[id].lower_bound(now.x);
                        if(jt==sty[id].begin())
                              flag=1;
                        else
                        {
                              jt--;
                              now.x=*jt+1;
                              now.dir=1;
                              if(vis.count(now))
                                    break;
                              vis.insert(now);
                        }
                  }
                  if(flag)
                        break;
                  sum++;
            }
            if(!flag)
                  sum=-1;
            printf("%d\n",sum);
      }
}
