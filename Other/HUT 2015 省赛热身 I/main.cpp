/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-27-12.04
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

const int MAXN=1000020;
vector<int> Next;
char s1[MAXN],s2[MAXN];

void GetNext()
{
      int k=0;
      int len=strlen(s2);
      Next.push_back(0);
      for(int i=1;i<len;++i)
      {
            while(k!=0 && s2[i]!=s2[k])
                  k=Next[k-1];
            if(s2[i]==s2[k])
                  ++k;
            Next.push_back(k);
      }
}


void KMP()
{
      Next.clear();
      int ans=0;
      GetNext();
      int l1=strlen(s1),l2=strlen(s2),k=0;
      for(int i=0;i<l1;++i)
      {
            while(k>0 &&s1[i]!=s2[k])
            {
                  k=Next[k-1];
            }
            if(s1[i]==s2[k])
                  ++k;
            if(k==l2)
            {
                  ++ans;
                  k=0;
            }
      }
      printf("%d\n",ans);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%s%s",s1,s2);
            KMP();
      }
      return 0;
}
/*

*/
