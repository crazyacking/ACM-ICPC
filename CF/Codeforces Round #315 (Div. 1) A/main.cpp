/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-11-00.40
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

const int NN=70000010;
bool v[NN];
int p[4118064];
int num=-1;
void makePrime()
{
      int i,j;
      v[0]=v[1]=1;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[1LL*i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
//      cout<<num<<endl;
//      for(int i=0;i<20;++i)
//      {
//            if(!v[i])
//            {
//                  printf("%d ",i);
//            }
//      }
}



char s[100];
int len;
bool judge(int x)
{
      sprintf(s,"%d",x);
      len=strlen(s);
      bool flag=true;
      for(int i=0;i<len/2;++i)
      {
            if(!(s[i]==s[len-i-1]))
            {
                  flag=false;
                  break;
            }
      }
      return flag;

}

int main()
{
      makePrime();
      int x,y;
      while(~scanf("%d %d",&x,&y))
      {
            int ans=-1;
            int c1=0,c2=0;
            for(int i=1;i<=4000000;++i)
            {
                  if(!v[i]) c1++;
                  if(judge(i)) c2++;
                  if(1LL*c1*y<=1LL*c2*x)
                        ans=ans>i?ans:i;
            }
            if(ans>0)
                  printf("%d\n",ans);
            else
                  puts("Palindromic tree is better than splay tree");
      }

      return 0;
}
/*

*/
