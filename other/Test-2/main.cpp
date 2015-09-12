/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-05-09-21.22
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
const int MAXN=100010<<1;
//以下为倍增算法求后缀数组
int wa[MAXN],wb[MAXN],wv[MAXN],Ws[MAXN];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
/**< 传入参数：str,sa,len+1,ASCII_MAX+1 */
void da(const char *r,int *sa,int n,int m)
{
      int i,j,p,*x=wa,*y=wb,*t;
      for(i=0; i<m; i++) Ws[i]=0;
      for(i=0; i<n; i++) Ws[x[i]=r[i]]++;
      for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
      for(i=n-1; i>=0; i--) sa[--Ws[x[i]]]=i;
      for(j=1,p=1; p<n; j*=2,m=p)
      {
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) Ws[i]=0;
            for(i=0; i<n; i++) Ws[wv[i]]++;
            for(i=1; i<m; i++) Ws[i]+=Ws[i-1];
            for(i=n-1; i>=0; i--) sa[--Ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                  x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
      }
      return;
}
int sa[MAXN],Rank[MAXN],height[MAXN];
/**< str,sa,len */
void calheight(const char *r,int *sa,int n)
{
      int i,j,k=0;
      for(i=1; i<=n; i++) Rank[sa[i]]=i;
      for(i=0; i<n; height[Rank[i++]]=k)
            for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
      // Unified
      for(int i=n;i>=1;--i) ++sa[i],Rank[i]=Rank[i-1];
}

char s1[MAXN],s2[MAXN];
int main()
{
      while(~scanf("%s%s",s1,s2))
      {
            int l1=strlen(s1);
            strcat(s1,"{");
            strcat(s1,s2);
            int len=strlen(s1);
            for(int i=0;i<len;++i) s1[i]-='a'-1;
            da(s1,sa,len+1,30);
            calheight(s1,sa,len);
            int ans=0;
            for(int i=2;i<=len;++i)
                  if((sa[i-1]-1<l1 && sa[i]-1>l1) || (sa[i-1]-1>l1 && sa[i]-1<l1))
                        ans=max(ans,height[i]);
            printf("%d\n",ans);
      }
      return 0;
}
