/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-05-11.38
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

void get1(LL n,LL arr[]) { /**< 求1~n所有数各个位上1的个数之和 */
      for(int i=1; i<32; ++i) arr[i]=0;
      for(LL i=1,f=2,b=1; b<=n; ++i,f<<=1,b<<=1) {
            arr[i]=(n/f)*(f/2); /**< 对于每一位,1~n可分为n/t组(t是每组的01数量)，其中每组有t/2个是1 */
            if(n%f>=b) arr[i]+=(n%f-b+1); /**< 加上余数部分 */
      }
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL n,t;
      cin>>t;
      while(t--) {
            LL A,B,C,D,Mod,a1[32],b1[32],c1[32],d1[32];
            cin>>A>>B>>C>>D>>Mod;
            get1(A-1,a1); get1(B,b1); get1(C-1,c1); get1(D,d1);
            LL ab1[32],ab0[32],cd1[32],cd0[32];
            for(int i=1; i<32; ++i) ab1[i]=b1[i]-a1[i],cd1[i]=d1[i]-c1[i];
            int l1=B-A+1,l2=D-C+1;
            for(int i=1; i<32; ++i) ab0[i]=l1-ab1[i],cd0[i]=l2-cd1[i];
            LL sum=0,base=1;
            for(int i=1; i<32; ++i)
                  sum=(sum+(base<<(i-1))%Mod*(ab0[i]%Mod *cd1[i]%Mod +ab1[i]%Mod*cd0[i]%Mod)%Mod)%Mod;
            cout<<sum<<endl;
      }
      return 0;
}
/*

*/
