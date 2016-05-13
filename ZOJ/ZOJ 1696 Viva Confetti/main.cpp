/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-22.53
* Time: 45MS
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
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define FORD(i,s,t) for(int i=(s-1); i>=t; i--)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;

const double eps = 1e-14;
const int MAX = 110;
const int BIG = 10000;
struct point
{
      double x, y;
      point(double x=0, double y=0):x(x), y(y) {}
};
int dcmp(double x)
{
      return x < -eps ? -1 : x > eps ? 1 : 0;
}
double disp2p(point a,point b) //  a b 两点之间的距离
{
      return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
// 叉积 (三点)
double crossProduct(point a,point b,point c)//向量 ac 在 ab 的方向 顺时针是正
{
      return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
struct circle
{
      point c;
      double r;
      void big()
      {
            c.x *= BIG;
            c.y *= BIG;
            r *= BIG;
      }
};
bool c2c_inst(point a,double r1,point b,double r2)
{
      if(dcmp(disp2p(a,b) - (r1+r2)) < 0 && dcmp(disp2p(a,b) - fabs(r1 - r2)) > 0)
            return true;
      return false;
}
circle c[MAX];
point l2l_inst_p(point u1,point u2,point v1,point v2)
{
      point ans = u1;
      double t = ((u1.x - v1.x)*(v1.y - v2.y) - (u1.y - v1.y)*(v1.x - v2.x))/
                 ((u1.x - u2.x)*(v1.y - v2.y) - (u1.y - u2.y)*(v1.x - v2.x));
      ans.x += (u2.x - u1.x)*t;
      ans.y += (u2.y - u1.y)*t;
      return ans;
}
void l2c_inst_p(point c,double r,point l1,point l2,point &p1,point &p2)
{
      point p = c;
      double t;
      p.x += l1.y - l2.y;
      p.y += l2.x - l1.x;
      p = l2l_inst_p(p,c,l1,l2);
      t = sqrt(r*r - disp2p(p,c)*disp2p(p,c))/disp2p(l1,l2);
      p1.x = p.x + (l2.x - l1.x)*t;
      p1.y = p.y + (l2.y - l1.y)*t;
      p2.x = p.x - (l2.x - l1.x)*t;
      p2.y = p.y - (l2.y - l1.y)*t;
}
void c2c_inst_p(point c1,double r1,point c2,double r2,point &p1,point &p2)
{
      point u,v;
      double t;
      t = (1 + (r1*r1 - r2*r2)/disp2p(c1,c2)/disp2p(c1,c2))/2;
      u.x = c1.x + (c2.x - c1.x)*t;
      u.y = c1.y + (c2.y - c1.y)*t;
      v.x = u.x + c1.y - c2.y;
      v.y = u.y - c1.x + c2.x;
      l2c_inst_p(c1,r1,u,v,p1,p2);
}
int see[MAX];
point ins[MAX], C;
bool cmp(point a,point b)
{
      double t1 = atan2(a.y - C.y, a.x - C.x);
      double t2 = atan2(b.y - C.y, b.x - C.x);
      if(dcmp(t1 - t2) == 0) return dcmp(fabs(a.x) - fabs(b.x)) < 0 ? true : false;
      return dcmp(t1 - t2) < 0 ? true : false;
}
int l2c_inst_p(point c,double r,point l1,point l2,point *pv)
{
      int cnt = 0;
      double d = fabs(crossProduct(c,l1,l2))/disp2p(l1,l2);
      if(dcmp(d-r) > 0)
            return 0;
      point p = c;
      double t;
      p.x += l1.y - l2.y;
      p.y += l2.x - l1.x;
      p = l2l_inst_p(p,c,l1,l2);
      t = sqrt(r*r - disp2p(p,c)*disp2p(p,c))/disp2p(l1,l2);
      pv[cnt].x = p.x + (l2.x - l1.x)*t;
      pv[cnt++].y = p.y + (l2.y - l1.y)*t;
      if(dcmp(d-r) == 0)
            return cnt;
      pv[cnt].x = p.x - (l2.x - l1.x)*t;
      pv[cnt++].y = p.y - (l2.y - l1.y)*t;
      return cnt;
}
//弧ab的中点
point mid_in_arc(point a, point b, point c, double r)
{
      point mid((a.x + b.x)/2, (a.y + b.y)/2);
      point p[3];
      int cnt = l2c_inst_p(c, r, mid, c, p);
      FOR(i, 0, cnt)
      if(crossProduct(c, a, p[i]) * crossProduct(c, p[i], b) && dcmp(crossProduct(c, a, p[i])) <= 0)
            return p[i];
}
int solve(int n)
{
      int ans = 0;
      memset(see, 0, sizeof(see));
      FOR(i, 0, n)
      {
            bool inst = false;
            int cnt = 0;
            FOR(k, i+1, n)
            {
                  double d = disp2p(c[i].c, c[k].c);
                  //被其他在它上面的圆包含了
                  if(dcmp(c[k].r - d - c[i].r) >= 0)
                  {
                        inst = true;
                        see[i] = -1;
                        break;
                  }
                  if(c2c_inst(c[i].c, c[i].r, c[k].c, c[k].r))
                        inst = true;
            }
            //与在它上面的圆都没有相交或包含在比它之上的圆中
            if(inst == false)
                  see[i] = 1;
            FOR(k, 0, n)
            {
                  if(k == i) continue;
                  if(!c2c_inst(c[i].c, c[i].r, c[k].c, c[k].r))
                        continue;
                  point a, b;
                  c2c_inst_p(c[i].c, c[i].r, c[k].c, c[k].r, a, b);
                  ins[cnt++] = a;
                  ins[cnt++] = b;
            }
            C = c[i].c;
            sort(ins, ins+cnt, cmp);
            FOR(k, 0, cnt)
            {
                  point mid = mid_in_arc(ins[k], ins[(k+1)%cnt], c[i].c, c[i].r);
                  double inf = 1e12;
                  point delta((c[i].c.x - mid.x)/(c[i].r*inf), (c[i].c.y - mid.y)/(c[i].r*inf));
                  point p(mid.x - delta.x, mid.y - delta.y);
                  for(int j=n-1; j>=0; j--)
                  {
                        if(dcmp(disp2p(p, c[j].c) - c[j].r) < 0)
                        {
                              if(see[j] == 0)
                              {
                                    see[j] = 1;
                              }
                              break;
                        }
                  }
                  p.x = mid.x + delta.x;
                  p.y = mid.y + delta.y;
                  bool nosee = false;
                  if(see[i] == 1)
                        continue;
                  FOR(j, i+1, n)
                  {
                        if(dcmp(disp2p(p, c[j].c) - c[j].r) < 0)
                        {
                              nosee = true;
                              break;
                        }
                  }
                  if(!nosee)
                        see[i] = 1;
            }
      }
      FOR(i, 0, n)
      ans += see[i] == 1 ? 1 : 0;
      return ans;
}

int main()
{
      int n;
      while(~scanf("%d", &n) && n)
      {
            FOR(i, 0, n)
            {
                  scanf("%lf%lf%lf", &c[i].c.x, &c[i].c.y, &c[i].r);
                  c[i].big();
            }
            int ans = solve(n);
            printf("%d\n", ans);
      }
      return 0;
}
