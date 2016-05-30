#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;

#define For(i,a,b) for(int i=(a); i<=(b); i++)
#define Rep(i,n) for(int i=0; i<(n); i++)
#define Size(x) (int(x.size()))
#define Fil(a) memset(&a,0,sizeof(a))

struct SuperString
{
  string goodnessSubstring(vs superstring)
  {
    string st,res;
    Rep(i,Size(superstring)) st+=superstring[i];
    res="";
    int best=0;
    Rep(i,Size(st))
    {
      int mx=0,pos=i-1;
      int cnt[26];
      Fil(cnt);
      int cur=0;
      For(j,i,Size(st)-1)
      {
        int k=st[j]-'A';
        ++cnt[k];
        if(cnt[k]==1) ++cur;
        else if(cnt[k]==2) --cur;
        if(cur>mx)
        {
          mx=cur;
          pos=j;
        }
      }
      if(mx<best) continue;
      string ss=st.substr(i,pos-i+1);
      if(mx>best || mx==best && ss<res)
      {
        best=mx;
        res=ss;
      }
    }
    return res;
  }
};

int main()
{
    int n;
    while(cin>>n)
    {
        vs v(n);
        for(int i=0;i<n;++i)
            cin>>v[i];
        SuperString ss;
        string  ans = ss.goodnessSubstring(v);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
