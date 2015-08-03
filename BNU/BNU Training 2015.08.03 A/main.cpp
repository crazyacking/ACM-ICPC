#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define LL long long
using namespace std;
const int mm=8+(int)4e5;
const int oo=2+(int)3e9;
map<int,int>mp;
map<int,int>::iterator it;
int f[mm],n,s,ans[mm],pos;
int main() {
      while(~scanf("%d%d",&n,&s)) {
            ans[0]=oo;
            FOR(i,1,n) {
                  scanf("%d",&f[i]);
            }
            sort(f+1,f+n+1);
            int l=1,r=n; pos=1;
            while(l<r) {
                  if(f[l]+f[r]>s)ans[pos++]=f[l++],ans[pos++]=f[r--];
                  else ans[pos++]=f[l++],ans[pos++]=f[l++];
            }
            if(l==r)ans[pos]=f[l];
            else pos--;
            int num=0;
            int zz=1;
            while(zz<=pos) {
                  //printf("zz=%d %d\n",ans[zz],ans[zz-1]);
                  LL zs=(LL)ans[zz]+(LL)ans[zz-1];
                  if(zs>s)++zz,++num;
                  else {
                        ++zz;//puts("++");
                        if(zz>pos)break; ++zz; ++num;
                  }
            }
            printf("%d\n",num);
            FOR(i,1,pos)
            printf("%d%c",ans[i],i==pos?'\n':' ');
      }
      return 0;
}
