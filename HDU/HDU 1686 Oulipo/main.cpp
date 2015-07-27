/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-27-15.58
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
const int N=10010,M=1000010;
char a[N],b[M];
int Next[N];
void getNext()
{
      int len=strlen(a);
      Next[0]=0;
      for(int i=1,k=0;i<len;++i)
      {
            while(a[i]!=a[k]&&k) k=Next[k-1];
            if(a[i]==a[k]) k++;
            Next[i]=k;
//            cout<<Next[i]<<endl;
      }
}
int kmp()
{
      int ans=0;
      getNext();
      int alen=strlen(a),blen=strlen(b);
      for(int i=0,k=0;i<blen;++i)
      {
            while(b[i]!=a[k]&&k) k=Next[k-1];
            if(a[k]==b[i]) ++k;
            if(k==alen)
            {
                  ans++;
                  k=Next[k-1];
            }
      }
      return ans;
}
int main()
{
//      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%s%s",a,b);
//            puts(a);
//            puts(b);
            printf("%d\n",kmp());
      }
      return 0;
}
/*

*/
