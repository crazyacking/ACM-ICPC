/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-27-16.41
* Time: 0MS
* Memory: 137KB
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


const int MAXN=1000010;
vector<int,set<int> > OLD[MAXN],NEW[MAXN];
int id[MAXN];
bool f1[MAXN],f2[MAXN];

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      for(int Cas=1;Cas<=t;++Cas)
      {
            int N;
            scanf("%d",&N);
            for(int i=0;i<MAXN;++i)
            {
                  OLD[i].clear();
                  NEW[i].clear();
                  f1[i]=f2[i]=false;
                  id[i]=-1;
            }
            int ol,ne;
            for(int i=0;i<N;++i)
            {
                  scanf("%d %d",&ol,&ne);
                  OLD[ol].insert(i);
                  NEW[ne].insert(i);
                  f1[ol]=true;
                  f2[ne]=true;
                  id[ne]=i;
            }
            for(int i=0;i<MAXN;++i)
            {
                  int set_id=-1;
                  if(f1[i])
                  {
                        for(auto ptr:OLD[i])
                        {
                              if(id[ptr]!=-1)
                              {
                                    set_id=id[ptr];
                              }
                        }
                  }
                  if(set_id)
            }
            for(int j=0;j<MAXN;++j)
            {

            }


      }
      return 0;
}
/*

*/
