/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-02-15.40
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
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


const int MAXN=100010;
char s[MAXN],ss[110];


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
//求height数组
/**< str,sa,len */
void calheight(const char *r,int *sa,int n)
{
      int i,j,k=0;
      for(i=1; i<=n; i++) Rank[sa[i]]=i;
      for(i=0; i<n; height[Rank[i++]]=k)
            for(k?k--:0,j=sa[Rank[i]-1]; r[i+k]==r[j+k]; k++);
      // Unified
      for(int i=n; i>=1; --i) ++sa[i],Rank[i]=Rank[i-1];
}

char str[MAXN];
int main()
{
      while(scanf("%s",str)!=EOF)
      {
            int len=strlen(str);
            da(str,sa,len+1,130);
            calheight(str,sa,len);
            puts("--------------All Suffix--------------");
            for(int i=1; i<=len; ++i)
            {
                  printf("%d:\t",i);
                  for(int j=i-1; j<len; ++j)
                        printf("%c",str[j]);
                  puts("");
            }
            puts("");
            puts("-------------After sort---------------");
            for(int i=1; i<=len; ++i)
            {
                  printf("sa[%2d ] = %2d\t",i,sa[i]);
                  for(int j=sa[i]-1; j<len; ++j)
                        printf("%c",str[j]);
                  puts("");
            }
            puts("");
            puts("---------------Height-----------------");
            for(int i=1; i<=len; ++i)
                  printf("height[%2d ]=%2d \n",i,height[i]);
            puts("");
            puts("----------------Rank------------------");
            for(int i=1; i<=len; ++i)
                  printf("Rank[%2d ] = %2d\n",i,Rank[i]);
            puts("------------------END-----------------");
      }
      return 0;
}
