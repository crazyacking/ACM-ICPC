/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-18-22.10
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

const int M=5100010;
char ss[M],str[M];

struct Node
{
      int cnt;
      Node *next[26];
};
Node *root;

inline void Build_Str(char *s)
{
      int len=strlen(s);
      int cnt=-1;
      for(int i=0;i<len;++i)
      {
            if(s[i]!='[')
                  str[++cnt]=s[i];
            else
            {
                  ++i;
                  int temp=0,base=1;
                  for(;s[i]>='0' && s[i]<='9';++i)
                  {
                        temp=(s[i]-'0')+temp*base;
                        base*=10;
                  }
                  char ch=s[i];
                  ++i;
                  for(int j=1;j<=temp;++j)
                        str[++cnt]=ch;
            }
      }
      puts(str);
}

inline void Insert(char *s)
{
      Node tmp=NULL;
      int i=0,index;
      while(s[i])
      {
            
      }
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int Cas;
      scanf("%d",&Cas);
      while(Cas--)
      {
            int n;
            scanf("%d",&n);
            root=NULL;
            for(int i=0;i<n;++i)
            {
                  scanf("%s",str);
                  Insert(str);
            }
            Build_ac_automation();
            scanf("%s",ss);
            Build_Str(ss);
            printf("%d\n",Query(str));
      }
      return 0;
}
/*

*/
