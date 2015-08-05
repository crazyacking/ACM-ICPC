/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-04-10.02
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
const int MAXN=100010;
vector<int> v1(MAXN),v2(MAXN);
int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,m,tmp;
      while(~scanf("%d %d",&n,&m)) {
            for(int i=0; i<n; ++i) {
                  scanf("%d",&tmp); v1[i]=tmp;
            }
            sort(v1.begin(),v1.begin()+n);
            int l=0,r=n-1,cnt=0,ans=0;
            while(l<r) {
                  if(v1[l]+v1[r]>m) v2[cnt++]=v1[l++],v2[cnt++]=v1[r--];
                  else v2[cnt++]=v1[l++],v2[cnt++]=v1[l++];
            }
            if(l==r) v2[cnt++]=v1[l];
            for(int i=0; i<n; ++i) {
                  ++ans;
                  if(v2[i]+v2[i+1]<=m) ++i;
            }
            printf("%d\n",ans);
            for(int i=0; i<n; ++i)
                  printf(i == n - 1 ? "%d\n" : "%d ", v2[i]);
      }
      return 0;
}
/*

*/
