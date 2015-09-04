/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-03-12.21
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

const int MAXN=10010,seed=131;
int n,id[MAXN];
char s[MAXN],str[1010];
vector<pair<int,int> >same;
bool isOk(int st,int en)
{
      int si=same.size();
      for(int i=0; i<si; ++i)
      {
            if(st>= (&same[i])->first && en<=(&same[i])->second)
                  return (&same[i])->first;
      }
      return -1;
}

vector<string> ans;
bool judge(int p,bool ty)
{
      vector<pair<ULL,pair<int,int> > >v;
      ULL hv=0,base=1;
      for(int i=0; i<p; ++i)
      {
            hv=hv*seed+s[i];
            base*=seed;
      }
      v.push_back(make_pair(hv,make_pair(0,p-1)));
      int len=strlen(s);
      for(int i=p; i<len; ++i)
      {
            hv=hv*seed+s[i] - base*s[i-p];
            v.push_back(make_pair(hv,make_pair(i-p+1,i)));
      }
      sort(v.begin(),v.end());
//      for(auto p2=v.begin();p2!=v.end();++p2)
//      {
//            int st=(&p2->second)->first;
//            int en=(&p2->second)->second;
//            int cnt=0;
//            for(int i=st;i<=en;++i)
//                  str[cnt++]=s[i];
//            str[cnt]='\0';
//            cout<<str<<endl;
//      }
      set<int> id;
      int st,en,cnt;
      bool f=false;
      ans.clear();
      auto p1=v.begin(),p2=v.begin();
      ++p2;
      for(; p2!=v.end(); ++p1,++p2)
      {
            if(p2->first != p1->first) id.clear();
            else
            {
                  while(p2->first == p1->first)
                  {
                        st=(&p2->second)->first;
                        en=(&p2->second)->second;
                        if(isOk(st,en)!=-1 && id.find(isOk(st,en))==id.end() &&
                                    isOk((&p1->second)->first,(&p1->second)->second)!=isOk(st,en))
                        {
                              id.insert(isOk(st,en));
                        }
                        ++p1,++p2;
                  }
                  --p1,--p2;
                  if((id.size()+1)*2>n)
                  {
                        f=true;
                        st=(&p2->second)->first;
                        en=(&p2->second)->second;
                        cnt=0;
                        for(int i=st; i<=en; ++i)
                              str[cnt++]=s[i];
                        str[cnt]='\0';
                        ans.push_back(str);
                        id.clear();
                  }
            }
      }
      if(!ty) return f;
      cout<<ans.size()<<endl;
      sort(ans.begin(),ans.end());
      for(int i=0; i<ans.size(); ++i)
      {
            cout<<ans[i]<<endl;
      }
}


int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(scanf("%d",&n),n)
      {
            same.clear();
            int maxLen=0,st,en;
            s[0]='\0';
            for(int i=0; i<n; ++i)
            {
                  scanf("%s",str);
                  st=strlen(s);
                  maxLen=max(maxLen,(int)strlen(str));
                  strcat(s,str);
                  en=strlen(s);
                  same.push_back(make_pair(st,en-1));
            }
            if(!judge(1,0))
            {
                  puts("?");
                  continue;
            }
            int l=1,r=maxLen,mid;
            while(r>l+1)
            {
                  mid=l+(r-l)/2;
                  if(judge(mid,0))
                  {
                        l=mid;
                        cout<<l<<endl;
                  }
                  else r=mid;
            }
            judge(l,1);
      }
      return 0;
}
/*

*/
