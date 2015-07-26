/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-26-14.30
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
const int MAXN=50+(int)1e6;
struct node{
      int x1,y1,x2,y2;
      bool operator<(node a)const
      {
            return x1==a.x1?y1<a.y1:x1<a.x1;
      }
};
node a[MAXN],b[MAXN];
int n,m;

struct point
{
      int x,y;
};

int xx(point &s,point &t)
{
    return (s.x*t.y+s.y*t.x);
}


bool kua(point A1,point B1,point A2,point B2)                           //跨立实验
 {
      point A1B1,B2B1,A2A1,B2A1;
     A1B1.x=A1.x-B1.x;  A1B1.y=A1.y-B1.y;
     B2B1.x=B2.x-B1.x;  B2B1.y=B2.y-B1.y;
     A2A1.x=A2.x-A1.x;  A2A1.y=A2.y-A1.y;
     B2A1.x=B2.x-A1.x;  B2A1.y=B2.y-A1.y;
     if(xx(A1B1,B2B1)*xx(B2B1,A2A1)>=0)
     {
         A1B1.y=-A1B1.y;A1B1.x=-A1B1.x;
         if(xx(A1B1,A2A1)*xx(A2A1,B2A1)>=0)
             return 1;
         else
             return 0;
     }
     else
         return 0;
 }


//bool Is_ok(int n1,int n2)
//{
//
//      int max_ax=max(a[n1].x1,a[n1].x2);
//      int min_ax=min(a[n1].x1,a[n1].x2);
//      int max_ay=max(a[n1].y1,a[n1].y2);
//      int min_ay=min(a[n1].y1,a[n1].y2);
//      //
//      int max_bx=max(b[n2].x1,b[n2].x2);
//      int min_bx=min(b[n2].x1,b[n2].x2);
//      int max_by=max(b[n2].y1,b[n2].y2);
//      int min_by=min(b[n2].y1,b[n2].y2);
//      if(max_ax>min_bx && )
//}

bool judge(int n1,int n2)
{
      point a1,b1,a2,b2;
      a1.x=a[n1].x1;
      a1.y=a[n1].y1;
      b1.x=a[n1].x2;
      b1.y=a[n1].y2;
      a2.x=b[n2].x1;
      a2.y=b[n2].y1;
      b2.x=b[n2].x2;
      b2.y=b[n2].y2;
      if(kua(a1,b1,a2,b2))
      {
            return true;
      }
      else return false;

}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      cin>>n;
      char ch;
      for(int i=0;i<n;++i)
      {
            cin>>a[i].x1>>ch>>a[i].y1>>a[i].x2>>ch>>a[i].y2;
      }
      sort(a,a+n);
      cin>>m;
      for(int i=0;i<m;++i)
      {
            cin>>b[i].x1>>ch>>b[i].y1>>b[i].x2>>ch>>b[i].y2;
      }
      for(int i=0;i<m;++i)
      {
            for(int j=0;j<n;++j)
            {
                  judge(i,j);
                  cout<<i<<endl;
            }
      }
      return 0;
}
/*

*/
