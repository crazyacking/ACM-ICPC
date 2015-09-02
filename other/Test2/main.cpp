#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXLEN = 200005;

struct Suffix_Arr
{
      int n, s[MAXLEN];
      int tmp_one[MAXLEN], tmp_two[MAXLEN], c[MAXLEN];
      int SA[MAXLEN], rank[MAXLEN], height[MAXLEN];

      void init();
      void build_arr(int m);
      void get_height();
} suf;

int N, maxlen, id[MAXLEN];

void init()
{
      maxlen = 0;
      suf.init();
      char word[1005];
      for(int i = 0; i < N; i++)
      {
            scanf("%s", word);
            if(N == 1)
            {
                  printf("%s\n", word);
                  return;
            }
            int len = strlen(word);
            maxlen = max(maxlen, len);
            for(int j = 0; j < len; j++)
            {
                  id[suf.n] = i;
                  suf.s[suf.n++] = word[j];
            }
            suf.s[suf.n++] = 'z' + i + 1;
      }
      suf.build_arr('z' + N + 1);
      suf.get_height();
}


bool judge(int l, int flag)
{
      set<int> vis;
      vis.insert(id[suf.SA[0]]);
      for(int i = 1; i < suf.n; i++)
      {
            while(i < suf.n && suf.height[i] >= l)
                  vis.insert(id[suf.SA[i++]]);
            if(vis.size() * 2 > N)
            {
                  if(flag)
                        return true;
                  for(int j = 0; j < l; j++)
                        printf("%c", suf.s[suf.SA[i-1] + j]);
                  printf("\n");
            }
            vis.clear();
            vis.insert(id[suf.SA[i]]);
      }
      return false;
}

void solve()
{
      if(N == 1)
            return;
      if(!judge(1, 1))
      {
            printf("?\n");
            return;
      }
      int l = 1, r = maxlen + 1;
      cout<<l<<" "<<r<<endl;
      while(l < r)
      {
            int mid = (l + r) / 2;
            if(judge(mid, 1))
                  l = mid + 1;
            else
                  r = mid;
      }
      judge(l - 1, 0);
}

int main()
{
      int cas = 0;
      while(scanf("%d", &N) == 1 && N)
      {
            if(cas++)
                  printf("\n");
            init();
            solve();
      }
      return 0;
}

void Suffix_Arr::init()
{
      n = 0;
}

void Suffix_Arr::get_height()
{
      for(int i = 0; i < n; i++) rank[SA[i]] = i;
      int k = 0;
      for(int i = 0; i < n; i++)
      {
            if(k) k--;
            if(rank[i] == 0)
                  continue;
            int j = SA[rank[i]-1];
            while(s[i+k] == s[j+k]) k++;
            height[rank[i]] = k;
      }
}

void Suffix_Arr::build_arr(int m)
{
      int *x = tmp_one, *y = tmp_two;
      for(int i = 0; i < m; i++) c[i] = 0;
      for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
      for(int i = 1; i < m; i++) c[i] += c[i-1];
      for(int i = n-1; i >= 0; i--) SA[--c[x[i]]] = i;
      for(int k = 1; k <= n; k <<= 1)
      {
            int mv = 0;
            for(int i = n - k; i < n; i++) y[mv++] = i;
            for(int i = 0; i < n; i++) if(SA[i] >= k)
                  {
                        y[mv++] = SA[i] - k;
                  }
            for(int i = 0; i < m; i++) c[i] = 0;
            for(int i = 0; i < n; i++) c[x[y[i]]]++;
            for(int i = 1; i < m; i++) c[i] += c[i-1];
            for(int i = n-1; i >= 0; i--) SA[--c[x[y[i]]]] = y[i];
            swap(x, y);
            mv = 1; x[SA[0]] = 0;
            for(int i = 1; i < n; i++)
                  x[SA[i]] = (y[SA[i-1]] == y[SA[i]] && y[SA[i-1] + k] == y[SA[i] + k] ? mv - 1 : mv++);
            if(mv >= n)
                  break;
            m = mv;
      }
}
