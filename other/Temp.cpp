# include<stdio.h>
# include<string.h>
int dp[105][105];
int map[105][105];
//首先用一个sum[][]来保存从第一行开始的和

int main()
{
    int i,j,n,i1,i2,sum,temp,max,res;
    while(scanf("%d",&n)!=EOF)
    {
      for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
          scanf("%d",&map[i][j]);

       memset(dp,0,sizeof(dp));
       for(j=1;j<=n;j++)             //控制列
         for(i=1;i<=n;i++)          //控制行
            dp[j][i]=dp[j][i-1]+map[i][j];   //dp[j][i]代表第j列从第1行开始的数累加到到第i行的和
       res=0;
       for(i1=1;i1<=n;i1++)           //i1,i2控制行的组合
         for(i2=i1;i2<=n;i2++)
         {
            max=sum=0;
           for(j=1;j<=n;j++)      //j控制在该行组合下的列
           {
              sum+=dp[j][i2]-dp[j][i1-1]; //表示第 j 列从第i1到i2行数字之和

             if(sum>=0)    //下面即为求最大连续子串和思想
             {
               if(sum>=max)
                  max=sum;
             }
             else
                 sum=0;
            }
            if(max>=res)
               res=max;
         }
      printf("%d\n",res);
    }
    return 0;
}


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int g[MAXN][MAXN];
int s[MAXN][MAXN];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(s,0,sizeof s);
        memset(g,0,sizeof g);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
                cin>>g[i][j];
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                s[i][j]=g[i][j]+g[i-1][j];
            }
        }
        int temp[MAXN];
        int ans=INT_MIN;
        for(int sta=1;sta<=n;++sta)
        {
            for(int en=sta;en<=n;++en)
            {
                for(int i=1;i<=m;++i)
                {
                    temp[i]=s[en][i]-s[sta][i];
                }
                int sum=0;
                int maxx=INT_MIN;
                for(int i=1;i<=m;++i)
                {
                    sum+=temp[i];
                    if(sum<0)
                        sum=0;
                    if(sum>maxx)
                    {
                        maxx=sum;
                    }
                }
                if(maxx>ans)
                {
                    ans=maxx;
                }
            }
        }
        
        cout<<ans<<endl;
    }
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namepsace std;
const int MAXN=10010;

struct Node
{
    int x,y,val;
};
Node a[MAXN];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int cnt=0;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                cin>>a[cnt].val;
                a[cnt].x=i,a[cnt].y=j;
                cnt++;
            }
    }
    
    int dp[MAXN];
    memset(dp,0,sizeof dp);
    dp[0]=1;
    int res=INT_MIN;
    for(int i=0;i<n;++i)
    {
        int maxx=INT_MIN;
        for(int j=0;j<i;++j)
        {
            int maxx=INT_MIN;
            if(abs(a[j].x-a[i])==1 && abs(a[j].y-a[i].y)==0 &&  (a[j].val<a[i].val) &&  ( dp[j]>maxx ) ))
            {
                maxx=dp[j];
            }
            if(abs(a[j].x-a[i].x)==0 && abs(a[j].y-a[i].y)==1 &&  (a[j].val<a[i].val) &&  ( dp[j]>maxx ) ))
            {
                maxx=dp[j];
            }
        }
        dp[i]=maxx+1;
        if(dp[i]>res)
        res=dp[i];
    }
    cout<<res<<endl;
    return 0;
}

