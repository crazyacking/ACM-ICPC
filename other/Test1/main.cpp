/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-25-12.26
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
using namespace std;
typedef __int64(LL);
typedef unsigned __int64(ULL);
const double eps(1e-8);
const int MAXN=100010*2;
int wa[MAXN],wb[MAXN],wv[MAXN],Ws[MAXN];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
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
void calheight(const char *r,int *sa,int n)
{
      int i,j,k=0;
      for(i=1; i<=n; i++) Rank[sa[i]]=i;
      for(i=0; i<n; height[Rank[i++]]=k)
            for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
      return;
}

char str1[MAXN];
int main()
{
      int t;
      scanf("%d",&t);
      getchar();
      for(int Cas=1; Cas<=t; ++Cas)
      {
            gets(str1);
            int l=strlen(str1);
            for(int i=l; i<(l<<1); ++i) str1[i]=str1[i%l];
            str1[l<<1]='\0';
            int len=strlen(str1);
            for(int i=0;i<len;++i) str1[i]-='0';
            da(str1,sa,len+1,12);
            calheight(str1,sa,len);
            int L=0,E=0,G=0;
            for(int i=1; i<=len/2; ++i)
            {
                  if(sa[i]+1<sa[Rank[len/2]]+1) ++L;
            }
            for(int i=len/2+1; i<=len; ++i)
            {
                  if(sa[i]+1<sa[Rank[len/2]]+1 && height[i]>=len/2) ++E;
                  if(height[i+1]<len/2) break;
            }
            G=len/2-E-L;
            printf("Case %d: %d %d %d\n",Cas,L,E,G);
      }
      return 0;
}
