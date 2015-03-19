//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-18-21.36
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<climits>
#include<cmath>
#define N 1000010
#define LL long long
using namespace std;

// my code is so ugly ==||
struct Node
{
        char c;
        int num;
} ss[200010],tt[200010];
char s[200010];
char t[200010];
int s1[230],t1[230],cnt[230];

struct MM
{
        int sum,iidx;
};
MM m[200010];
bool cmp(MM a,MM b)
{
        return a.sum<b.sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("C:\\Users\\ASUS\\Desktop\\cin.cpp","r",stdin);
//    freopen("C:\\Users\\ASUS\\Desktop\\cout.cpp","w",stdout);
    int len;
    while(cin>>len)
    {
            scanf("%s",s);
            scanf("%s",t);
            int idx=0;
            for(int i=0;i<len;++i)
            {
                    if(s[i]!=t[i])
                    {
                            ss[idx].c=s[i];
                            tt[idx].c=t[i];
                            ss[idx].num=i;
                            tt[idx].num=i;
                            m[idx].sum=ss[idx].c+tt[idx].c;
                            m[idx].iidx=idx;
                            idx++;
                    }
            }
            sort(m,m+idx,cmp);
            bool f1=0;
            int a,b;
            for(int i=1;i<idx;++i)
            {
                    if(m[i].sum==m[i-1].sum)
                    {
                            if(ss[m[i].iidx].c==tt[m[i-1].iidx].c && tt[m[i].iidx].c==ss[m[i-1].iidx].c)
                            {
                                    f1=1;
                                    a=ss[m[i].iidx].num;
                                    b=ss[m[i-1].iidx].num;
                                    cout<<idx-2<<endl;
                                    cout<<a+1<<" "<<b+1<<endl;
                                    break;
                            }
                    }
            }
            if(!f1)
            {
                    memset(s1,0,sizeof s1);
                    memset(t1,0,sizeof t1);
                    for(int i=0;i<idx;++i)
                    {
                            s1[ss[i].c]++;
                            t1[tt[i].c]++;
                    }
                    int c_int=-1;
                    for(int i=0;i<150;++i)
                    {
                            if(s1[i]>0 && t1[i]>0)
                            {
                                c_int=i;
                            }
                    }
                    a=-1,b=-1;
                    for(int i=0;i<idx;++i)
                    {
                            if(ss[i].c==c_int)
                            {
                                    a=ss[i].num;
                            }
                            if(tt[i].c==c_int)
                            {
                                    b=tt[i].num;
                            }
                    }
                    if(a!=-1 && b!=-1)
                    {
                            int ans=idx-1;
                            cout<<ans<<endl;
                            cout<<b+1<<" "<<a+1<<endl;
                    }
                    else
                    {
                            cout<<idx<<endl;
                            cout<<-1<<" "<<-1<<endl;
                    }

            }
    }
    return 0;
}
/*

*/
