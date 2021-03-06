/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-27-14.58
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
int a[10010],b[1000010];
int n,m;
vector<int>Next;
void getNext()
{
      Next.clear();
      Next.push_back(0);
      for(int i=1,k=0;i<m;++i)
      {
            while(a[i]!=a[k] && k)
                  k=Next[k-1];
            if(a[i]==a[k]) k++;
            Next.push_back(k);
      }
}

int kmp()
{
      int pos=-1;
      for(int i=0,k=0;i<n;++i)
      {
            while(a[k]!=b[i] && k)
                  k=Next[k-1];
            if(a[k]==b[i]) k++;
            if(k==m)
            {
                  pos=i-k+2;
                  break;
            }
      }
      return pos;
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
            scanf("%d %d",&n,&m);
            for(int i=0;i<n;++i)scanf("%d",&b[i]);
            for(int i=0;i<m;++i)scanf("%d",&a[i]);
            getNext();
            int ans=kmp();
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
