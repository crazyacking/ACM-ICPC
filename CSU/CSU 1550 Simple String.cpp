//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-29-12.08
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define MAXN 1000010
#define LL long long
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
//      freopen("C:\\Users\\Devin\\Desktop\\cin.cpp","r",stdin);
//      freopen("C:\\Users\\Devin\\Desktop\\cout.cpp","w",stdout);
        string a,b,c;
        while(cin>>a>>b>>c)
        {
                bool flag=true;
                int len=a.length();
                int aa[26],bb[26],cc[26],dd[26];
                memset(aa,0,sizeof aa),memset(bb,0,sizeof bb),memset(cc,0,sizeof cc),memset(dd,0,sizeof dd);
                for(int i=0;i<len;++i)
                {
                        aa[a[i]-'A']++;
                        bb[b[i]-'A']++;
                        cc[c[i]-'A']++;
                }
                for(int i=0;i<26;++i)
                {
                        if(aa[i]+bb[i]<cc[i])
                        {
                                flag=false;
                                puts("NO");
                                break;
                        }
                }
                if(!flag) continue;
                for(int i=0;i<26;++i)
                {
                        dd[i]=cc[i]-aa[i];
                }
                int sum=0;
                for(int i=0;i<26;++i)
                {
                        if(dd[i]>0)
                        {
                                sum+=dd[i];
                                if(dd[i]>bb[i])
                                {
                                        flag=false;
                                        break;
                                }
                        }

                }
                if(!flag)
                {
                        puts("NO");
                        continue;
                }
                int half=len/2;
                sum=0;
                for(int i=0;i<26;++i)
                {
                        if(dd[i]<=0)
                        {
                                sum+=min(bb[i],cc[i]);
                        }
                        else
                        {
                                sum+=min(bb[i],cc[i]);
                        }
                }
                if(sum>=half)
                {
                        puts("YES");
                        continue;
                }
                else
                {
                        puts("NO");
                        continue;
                }
        }
        return 0;
}
/*

*/
/**************************************************************
    Problem: 1550
    User: crazyacking
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1976 kb
****************************************************************/





//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-29-12.08
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define MAXN 1000010
#define LL long long
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
//      freopen("C:\\Users\\Devin\\Desktop\\cin.cpp","r",stdin);
//      freopen("C:\\Users\\Devin\\Desktop\\cout.cpp","w",stdout);
        string a,b,c;
        while(cin>>a>>b>>c)
        {
                bool flag=true;
                int len=a.length();
                int aa[26],bb[26],cc[26],dd[26];
                memset(aa,0,sizeof aa),memset(bb,0,sizeof bb),memset(cc,0,sizeof cc),memset(dd,0,sizeof dd);
                for(int i=0;i<len;++i)
                {
                        aa[a[i]-'A']++;
                        bb[b[i]-'A']++;
                        cc[c[i]-'A']++;
                }
                for(int i=0;i<26;++i)
                {
                        if(aa[i]+bb[i]<cc[i])
                        {
                                flag=false;
                                puts("NO");
                                break;
                        }
                }
                if(!flag) continue;
                for(int i=0;i<26;++i)
                {
                        dd[i]=cc[i]-aa[i];
                }
                int sum=0;
                for(int i=0;i<26;++i)
                {
                        if(dd[i]>0)
                        {
                                sum+=dd[i];
                                if(dd[i]>bb[i])
                                {
                                        flag=false;
                                        break;
                                }
                        }

                }
                if(!flag)
                {
                        puts("NO");
                        continue;
                }
                int half=len/2;
                sum=0;
                for(int i=0;i<26;++i)
                {
                        if(dd[i]<=0)
                        {
                                sum+=min(bb[i],cc[i]);
                        }
                        else
                        {
                                sum+=min(bb[i],cc[i]);
                        }
                }
                if(sum>=half)
                {
                        puts("YES");
                        continue;
                }
                else
                {
                        puts("NO");
                        continue;
                }
        }
        return 0;
}
/*

*/
/**************************************************************
    Problem: 1550
    User: crazyacking
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1976 kb
****************************************************************/
