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

const int MAXN=6000010;

char s1[MAXN],s2[MAXN],ans[MAXN];
int a[MAXN],pr[MAXN];
int main()
{
      while(scanf("%s%s",s1+1,s2+1)!=EOF)
      {
            int l1=strlen(s1+1);
            int l2=strlen(s2+1);
            for(int i=1;i<=l2;++i){
                  pr[i]=i-1;
            }
            int tol=0;
            for(int i=1;i<=l2;++i)
            {
                  ans[++tol]=s2[i];
                  if(s1[a[pr[i]]+1]==s2[i])
                  {
                        a[i]=a[pr[i]]+1;
                        if(a[i]==l1)
                        {
                              int p=i;
                              for(int j=1;j<=l1;++j){
                                    --tol;
                                    p=pr[p];
                              }
                              pr[i+1]=p;
                        }
                  }
                  else
                        a[i]=(s1[1]==s2[i]);
            }
            ans[++tol]='\0';
            puts(ans+1);
      }
      return 0;
}
/*

*/
