/*
简单DP
由于数据规模过大不能直接用LCS的算法
需要间接的转化成LIS用nlog（n）算法解决
方法是记录b数列中数字在a中出现的位置求一个LIS就可以了

*/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;

#define MAXN 250


int n,n1,n2;
int b[MAXN*MAXN+5],tp,f[MAXN*MAXN+5];
map<int ,int> mii;

int binSea(int x,int len)
{
      int left=0,right=len,cnt=0;
      while(left<=right)
      {
            int mid=(left+right)>>1;
            if(x>f[mid])
            {
                  cnt=mid;
                  left=mid+1;
            }
            else right=mid-1;
      }
      return cnt;
}
int main()
{
      int cs;
      scanf("%d",&cs);
      for(int ts=1; ts<=cs; ts++)
      {
            scanf("%d%d%d",&n,&n1,&n2);
            mii.clear();
            for(int i=1; i<=n1+1; i++)
            {
                  int s;
                  scanf("%d",&s);
                  mii[s]=i;
            }
            tp=0;
            for(int i=1; i<=n2+1; i++)
            {
                  int s;
                  scanf("%d",&s);
                  if(mii.count(s)!=0) b[tp++]=mii[s];
            }

            int ans=0,tmp;
            f[0]=-1;
            for(int i=0; i<tp; i++)
            {
                  tmp=(binSea(b[i],ans)+1);
                  if(tmp>ans)
                  {
                        f[tmp]=b[i];
                        ans=tmp;
                  }
                  else if(f[tmp]>b[i])
                        f[tmp]=b[i];
            }
            printf("Case %d: %d\n",ts,ans);
      }
      return 0;
}
