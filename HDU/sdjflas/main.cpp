/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-28-12.46
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

const int NN=10000010;
bool v[NN];
int p[NN];
void makePrime()
{
      int num=-1,i,j;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
//      cout<<num<<endl;
}


const int MAXN=1000010;
int cnt[MAXN];
void countPrime()
{
      LL tmp,j;
      for(int i=0;i<664578;++i)
      {
            j=1;
            tmp=j*p[i];
            while(tmp<MAXN)
            {
                  ++cnt[tmp];
                  ++j;
                  tmp=j*p[i];
            }
      }
}


int l,r;


set<int> se;

int gcd(int a,int b)
{
      return !b?a:gcd(b,a%b);
}



int Gcd[1100][1100];
void makeGcd()
{
      for(int i=1;i<1100;++i)
      {
            for(int j=1;j<1100;++j)
            {
                  Gcd[i][j]=gcd(i,j);
            }
      }
}

int main()
{
      makePrime();
      countPrime();
      makeGcd();
      int k;
      int T;
//      scanf("%d",&T);
//      for(int l=2;l<=1000;++l)
//      while()      int l=2;C
      int l,r;
      while(cin>>l>>r)
      {
            se.clear();
//            scanf("%d %d",&l,&r);
//            if(l>r) swap(l,r);
            for(int i=l;i<=r;++i)
            {
                  se.insert(cnt[i]);
            }
            set<int>::iterator t1,t2;
            int gc;

            int ans=INT_MIN;
            if(se.size()==1)
            {
                  printf("%d\n",1);
                  continue;
            }
            for(t1=se.begin();t1!=se.end();++t1)
            {
                  for(t2=se.begin();t2!=se.end();++t2)
                  {
                        if(t1!=t2)
                        {
                              gc=Gcd[(*t1)][(*t2)];
                              ans=ans>gc?ans:gc;

                        }
                  }
            }
//            if(k!=ans)
//            {
                  printf("%d %d\n",r,ans);
//            }
////            printf("%d ",ans);
//            k=ans;
      }

      return 0;
}
/*

*/
