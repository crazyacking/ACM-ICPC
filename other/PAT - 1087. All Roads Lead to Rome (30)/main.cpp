#include <stdio.h>
#include <map>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
#define  INF 0xfffffff

int n,m;
int d[205],w[205][205],hp[205],path[205],l[205],totalhp[205],av_hp[205];
bool vis[205];
map<string,int> mp;
string str[205];
int num[205];

void Dj(int s)
{
      int i,j;
      for(i=0; i<n; i++)
            if(w[s][i]!=INF)
            {
                  d[i]=w[s][i],path[i]=s,totalhp[i]=hp[i],l[i]=1,num[i]=1;
            }
            else
                  d[i]=INF;
      d[s]=0;
      l[s]=0;
      num[s]=1;
      vis[s]=true;
      for(j=0; j<n-1; j++)
      {
            int min=INF,idx=-1;
            for(i=0; i<n; i++)
                  if(!vis[i]&&d[i]<min)
                        min=d[i],idx=i;
            vis[idx]=true;
            if(min==INF)
                  break;
            for(i=0; i<n; i++)
                  if(!vis[i]&&w[idx][i])
                  {
                        if(d[idx]+w[idx][i]<d[i])
                        {
                              num[i]=num[idx];
                              d[i]=d[idx]+w[idx][i];
                              path[i]=idx;
                              totalhp[i]=totalhp[idx]+hp[i];
                              l[i]=l[idx]+1;
                              av_hp[i]=totalhp[i]/l[i];
                        }
                        else if(d[idx]+w[idx][i]==d[i])
                        {
                              num[i]+=num[idx];
                              if(totalhp[idx]+hp[i]>totalhp[i]||(totalhp[idx]+hp[i]==totalhp[i]&&l[idx]+1<l[i]))
                              {
                                    path[i]=idx;
                                    totalhp[i]=totalhp[idx]+hp[i];
                                    l[i]=l[idx]+1;
                                    av_hp[i]=totalhp[i]/l[i];
                              }
                        }
                  }

      }
}


int main()
{
      scanf("%d%d",&n,&m);
      int i,j;
      for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                  w[i][j]=INF;
      char a1[10];
      scanf("%s",a1);
      mp[a1]=0;
      char a[10];
      int t;
      for(i=1; i<n; i++)
      {
            scanf("%s",a),scanf("%d",&t);
            str[i]=a,mp[a]=i,hp[i]=t;
      }
      char b[10];
      for(i=0; i<m; i++)
      {
            scanf("%s%s%d",a,b,&t);
            int x=mp[a],y=mp[b];
            if(t<w[x][y])
                  w[x][y]=w[y][x]=t;
      }
      i=mp["ROM"];
      Dj(0);
      printf("%d %d %d %d\n",num[i],d[i],totalhp[i],av_hp[i]);
      vector<int> v;
      j=path[i];
      while(j!=0)
            v.push_back(j),j=path[j];
      i=v.size()-1;
      printf("%s->",a1);
      for(j=i; j>=0; j--)
            printf("%s->",str[v[j]].c_str());
      printf("ROM\n");
      return 0;
}



