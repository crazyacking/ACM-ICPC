/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-03-22.50
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
typedef unsigned long long(ULL);
const double eps(1e-8);
typedef long long ll;

struct Rec
{
      int l, w;
      char ch;
      bool operator <(const Rec& rhs)const
      {
            return l < rhs.l;
      }
      int sq(){return l*w;}
};

Rec rec[4];

int main()
{
      while(scanf("%d%d%d%d%d%d", &rec[1].l, &rec[1].w, &rec[2].l, &rec[2].w, &rec[3].l, &rec[3].w) == 6)
      {
            for(int i = 1; i <= 3; i++)
            {
                  if(rec[i].l < rec[i].w)swap(rec[i].l, rec[i].w);
                  rec[i].ch = 'A' - 1 + i;
            }
            sort(rec + 1, rec + 4);
            int len = rec[3].l;
            if((rec[3].l*rec[3].l) != (rec[1].sq() + rec[2].sq() + rec[3].sq()))
            {
                  printf("-1\n");
                  continue;
            }
            printf("%d\n", len);
            for(int i = 1; i <= rec[3].w; i++)
            {
                  for(int j = 1; j <= rec[3].l; j++)
                        printf("%c", rec[3].ch);
                  printf("\n");
            }
            if(rec[2].l!=len&&rec[3].w + rec[2].w != len) swap(rec[2].l, rec[2].w);
            for(int i = 1; i <= rec[2].w; i++)
            {
                  for(int j = 1; j <= rec[2].l; j++)
                        printf("%c", rec[2].ch);
                  for(int j = 1; j <= len - rec[2].l; j++)
                        printf("%c", rec[1].ch);
                  printf("\n");
            }
            for(int i = 1; i <=len-rec[3].w- rec[2].w; i++)
            {
                  for(int j = 1; j <= len; j++)
                        printf("%c", rec[1].ch);
                  printf("\n");
            }
      }
      return 0;
}
