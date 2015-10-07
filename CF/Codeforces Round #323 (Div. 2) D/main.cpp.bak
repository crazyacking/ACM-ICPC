#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
typedef long long ll;
using namespace std;
#define rep1(i ,x ,n) for(int i=x;i<=n;i++)
#define lowbit(x) (x&(-x))

const int N = 350;
int a[N] , cnt[N] ,d[N]= {0},n,T;
int main()
{
      cin>>n>>T;
      rep1(i ,1 , n) scanf("%d",&a[i]),cnt[a[i]]++;
      int max_ = 0;
      rep1(i ,1 , n) max_ = max(max_,cnt[a[i]]);
      int min_ = min(T, 200);
      rep1(i , 1 , min_)
      {
            rep1(j , 1 , n)
            {
                  int te = 0;
                  rep1(k ,1 ,n) if(a[k] <= a[j])
                  {
                        te = max(te , d[k]+1);
                  }
                  d[j] = te;
            }
      }
      int res = 0;
      rep1(i ,1 , n)
      {
            rep1(j,1,a[i])
            {
                  res=max(res,d[i]+(T - min_)*cnt[j]);
            }
      }
      cout<<res<<endl;
      return 0;
}
