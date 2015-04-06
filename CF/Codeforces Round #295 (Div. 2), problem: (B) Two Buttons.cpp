#include<algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include<queue>
#include<set>
#include<stack>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#define __LL64 long long
#define clr(a) memset(a,0,sizeof a)
using namespace std;
const double pi  = acos(-1.0);
const double eps = 1e-9;
const long long M = 1e9+7 ;
const long long INF = 0x3f3f3f3f;
typedef long long LL;
typedef unsigned long long ULL;
const LL dir[4][2] = {-1,0,0,-1,0,1,1,0};
using namespace std;

LL _buf[20];
inline long long read()
{
    char c = getchar();
    LL isMinus = 1;
    long long x = 0;
    while ( c!='-' && ( c<'0' || c>'9' )) c = getchar();
    if (c=='-') {isMinus = -1;c= getchar();}
    while ( c>='0' &&c<='9' ) {x = x*10+c-'0';c=getchar();}
    return x * isMinus;
}
inline void write(long long num,LL flag = 1)
{
    memset(_buf,0,sizeof(_buf));
    if (num<0) {putchar('-');num=-num;}
    LL p = 0;
    if (num==0) p++;
    else while (num){_buf[p++]=num%10;num/=10;}
    for (LL i=p-1;i>=0;--i) putchar(_buf[i]+'0');
    if (flag==1) puts("");
    if (flag==0) printf(" ");
}
const LL Max = 50*50;

int main(){
    int n,m;
    while (cin>>n>>m)
    {
        set<int>s;
        queue<pair<int,int>>q;
        q.push({n,0});
        while (!q.empty())
        {

            pair<int,int>  p = q.front();
            q.pop();

            if (p.first<=0) continue;
            if (p.first==m)
            {
                write(p.second);
                break;
            }

            else {
                s.insert(p.first);
                 if (s.count(p.first-1)==0) q.push({p.first-1,p.second+1});
                if (p.first<m && s.count(p.first*2)==0) q.push({p.first*2,p.second+1});
            }

        }
    }
    return 0;
}
