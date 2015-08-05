/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-04-12.41
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
/**< 暴力对拍程序 */
set<string> ss1,ss2,ss;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      string s1,s2;
      while(cin>>s1>>s2)
      {
            int l1=s1.length();
            int l2=s2.length();
            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

            ss1.clear(),ss2.clear(),ss.clear();
            for(int i=0;i<l1;++i)
            {
                  for(int j=i;j<l1;++j)
                  {
                        string tmp=s1.substr(i,j-i+1);
                        if(ss1.find(tmp)!=ss1.end()) cout<<tmp<<endl;
                        else ss1.insert(tmp);
                  }
            }
            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

            for(int i=0;i<l2;++i)
            {
                  for(int j=i;j<l2;++j)
                  {
                        string tmp=s2.substr(i,j-i+1);
                        if(ss2.find(tmp)!=ss2.end()) cout<<tmp<<endl;
                        else ss2.insert(tmp);
                  }
            }
            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");
            vector<string> v1,v2;
            set<string>::iterator it;
            for(it=ss1.begin();it!=ss1.end();++it)
            {
                  v1.push_back(*it);
            }
            for(it=ss2.begin();it!=ss2.end();++it)
            {
                  v2.push_back(*it);
            }

            //
            for(int i=0;i<v1.size();++i)
            {
                  ss.insert(v1[i]);
            }
            for(int i=0;i<v2.size();++i)
            {
                  ss.insert(v2[i]);
            }
            //
            for(int i=0;i<v1.size();++i)
            {
                  for(int j=0;j<v2.size();++j)
                  {
                        ss.insert(v1[i]+v2[j]);
                  }
            }

//            for(it=ss.begin();it!=ss.end();++it)
//            {
//                  cout<<(*it)<<endl;
//            }
            cout<<ss.size()+1<<endl;

      }
      return 0;
}
/*

*/

/**< 正式程序 */
/*
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
const int MAXN=90010;

int l1,l2;
char s1[MAXN],s2[MAXN];
vector<vector<int> > cnt1(130),cnt2(130);
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%s%s",s1,s2);
            l1=strlen(s1),l2=strlen(s2);
            for(int i=0;i<130;++i) cnt1[i].clear(),cnt2[i].clear();
            // cnt
            for(int i=0;i<l1;++i)
            {
                  char ch=s1[i];
                  int num=1;
                  if(s1[i]==s1[i+1])
                  {
                        while(s1[i]==s1[i+1])
                        {
                              ++i;
                              ++num;
                        }
                  }
                  cnt1[ch].push_back(num);
            }

            for(int i=0;i<l2;++i)
            {
                  char ch=s2[i];
                  int num=1;
                  if(s2[i]==s2[i+1])
                  {
                        while(s2[i]==s2[i+1])
                        {
                              ++i;
                              ++num;
                        }
                  }
                  cnt2[ch].push_back(num);
            }

            // test
            for(int i=97;i<123;++i)
            {
                  int si=cnt1[i].size();
                  printf("%c:",i);
                  for(int j=0;j<si;++j)
                  {
                        printf("%d ",cnt1[i][j]);
                  }
                  puts("");

            }
      }
      return 0;
}

*/
