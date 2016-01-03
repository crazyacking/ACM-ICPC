/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.49
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;
#define MAXD 1000010
#define MAXQ 25010
using namespace std;
int N, Q, X, p[MAXD], col[MAXD], s[MAXD];
struct Que
{
      int x, y, z;
      bool operator < (const Que &t) const
      {
            return z > t.z;
      }
} q[MAXQ], t[MAXQ];
int find(int x)
{
      int top = 0;
      while(p[x] != x)
            s[++ top] = x, x = p[x];
      while(top)
            p[s[top --]] = x;
      return x;
}
void init()
{
      int i;
      for(i = 1; i <= Q; i ++)
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
}
void refresh(int x, int y)
{
      int i = find(x - 1), j = find(x);
      if(col[i])
            p[i] = j;
      col[j] = 1;
      for(i = j; i <= y; i = j)
      {
            j = find(i + 1);
            if(col[j] || j <= y)
                  col[j] = 1, p[i] = j;
      }
}
int deal(int n)
{
      int i, j, x, y, tx, ty, fa;
      for(i = 0; i <= N + 1; i ++)
            p[i] = i, col[i] = 0;
      for(i = 1; i <= n; i ++)
            t[i] = q[i];
      sort(t + 1, t + 1 + n);
      for(i = 1; i <= n; i = j + 1)
      {
            x = tx = t[i].x, y = ty = t[i].y;
            for(j = i; j < n && t[j + 1].z == t[j].z;)
                  ++ j, x = max(x, t[j].x), y = min(y, t[j].y), tx = min(tx, t[j].x), ty = max(ty, t[j].y);
            if(x > y)
                  return 0;
            fa = find(x);
            if(col[fa] != 0 && find(fa) >= y)
                  return 0;
            refresh(tx, ty);
      }
      return 1;
}
void solve()
{
      int mid, min, max;
      min = 1, max = Q + 1;
      for(;;)
      {
            mid = (min + max) >> 1;
            if(mid == min)
                  break;
            if(deal(mid))
                  min = mid;
            else
                  max = mid;
      }
      printf("%d\n", mid == Q ? 0 : mid + 1);
}
int main()
{
      while(scanf("%d%d", &N, &Q) == 2)
      {
            init();
            solve();
      }
      return 0;
}
