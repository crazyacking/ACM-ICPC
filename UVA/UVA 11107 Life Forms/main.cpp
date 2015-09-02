/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-02-15.01
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

const int MAXN=10001010;
char s[MAXN],ss[1010];

//以下为倍增算法求后缀数组
int wa[MAXN*2],wb[MAXN*2],wv[MAXN],Ws[MAXN];
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


vector<pair<int,int> > same;
int found(int x)
{
      int si=same.size();
      for(int i=0;i<si;++i)
      {
            if(x>=same[i].first && x<=same[i].second)
                  return same[i].first;
      }
}

int len,n;
bool judge(int p,bool ty)
{
      bool f=false;
      set<int> sta;
      sta.insert(found(sa[1]-1));
      for(int i=2;i<=len;++i)
      {
            while(i<=len && height[i]>=p)
                  sta.insert(found(sa[i++]-1));
            if(sta.size()*2>n)
            {
                  if(ty) return true;
                  else
                  {
                        for(int j=0;j<p;++j)
                              printf("%c",s[sa[i-1]-1+j]+'a');
                        puts("");
                  }
            }
            sta.clear();
            sta.insert(found(sa[i]-1));
      }
      return f;
}


int main()
{
      int Cas=0;
      while(scanf("%d",&n),n)
      {
            same.clear();
            int st,en,maxLen=1;
            memset(s,0,sizeof s);
            for(int i=0;i<n;++i)
            {
                  scanf("%s",ss);
                  maxLen=max(maxLen,(int)strlen(ss));
                  st=strlen(s);
                  strcat(s,ss);
                  ss[0]='z'+1+i,ss[1]='\0';
                  strcat(s,ss);
                  en=strlen(s);
                  same.push_back(make_pair(st,en-1));
            }
            len=strlen(s);
            if(Cas++) puts("");
            if(n==1)
            {
                  s[len-1]='\0';
                  continue;
            }
            for(int i=0;i<len;++i) s[i]-='a';
            da(s,sa,len+1,130);
            calheight(s,sa,len);
            if(!judge(1,1))
            {
                  puts("?");
                  continue;
            }
            int l=1,r=maxLen+1,mid;
            while(r>l+1)
            {
                  int mid = l+(r-l)/2;
                  if(judge(mid,1)) l = mid;
                  else r = mid;
            }
            judge(l,0);
      }
      return 0;
}
/*

*/
