/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-26-19.12
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
#define  LL __int64
#define  ULL unsigned long long
using namespace std;
const int MAXN=2500050;
char ss[MAXN],s[MAXN];
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
//      freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            scanf("%s",ss);
            int cnt=0;
            n=strlen(ss);
            for(int i=0;i<n;++i)
            {
                  if(ss[i+1]>='0' && ss[i+1]<='9')
                  {
                        int num=0;
                        char ch=ss[i];
                        i++;
                        while(ss[i]>='0' && ss[i]<='9')
                        {
                              num=num*10+ss[i]-'0';
                              i++;
                        }
                        while(num)
                        {
                              s[cnt++]=ch;
                              num--;
                        }
                        --i;
                  }
                  else s[cnt++]=ss[i];
            }
            puts(s);
            LL res1=0,res2=0;
            s[cnt]='\0';
            int c[130]={0};
            int rp[130]={INT_MIN};
            for(int i=0;i<cnt;++i) c[s[i]]++,rp[s[i]]=rp[s[i]]>i?rp[s[i]]:i;
            for(int i=0;i<cnt;++i)
            {
                  int gap=rp[s[i]]-i;
                  cout<<"he="<<gap*5<<endl;
                  res1+=gap*5;
            }
            cout<<"res1="<<res1<<endl;
            for(int i=0;i<130;++i)
            {
                  res2+=(c[i])*(c[i]-1)*5/2;
            }
            if(res1>res2) printf("%I64d\n",res1-res2);
            else puts("0");
      }
      return 0;
}
/*

*/
