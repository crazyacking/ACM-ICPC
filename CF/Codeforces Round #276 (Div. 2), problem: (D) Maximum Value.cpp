#include<algorithm>
#include<bitset>
#include<cctype>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<iterator>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<strstream>
#include<string>
#include<utility>
#include<vector>
#include <cstdarg>
using namespace std;
/***************************************************************************************************************************************/
typedef long long int LLI;
typedef unsigned long long int ULLI;
#define MP(X,Y) make_pair(X,Y)

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define fill(a,v) memset(a,v,sizeof(a))
#define fillx(a,v,n) memset(a,v,n*sizeof(a[0]))
#define DEBUG(x) cout << #x << ": " << x << endl;
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define VI vector<int>
#define VS vector<string>
#define PB push_back
#define REV(a) reverse(all(a))
typedef pair<int, int>PII;

template<class T> inline T MIN_3(T a, T b, T c)
{
    return min(min(a, b), c);
}


template<class T> inline T MAX_3(T a, T b, T c)
{
    return max(max(a, b), c);
}

#define BRPS(n,bit) bitset<bit>(n)
#define LB(A, x) (lower_bound(all(A), x) - A.begin())//exactly where it starts
#define UB(A, x) (upper_bound(all(A), x) - A.begin())
#define UNQ(x) SORT(x),(x).erase(unique(all(x)),x.end())

template<class T> inline T BIGMOD(T n, T m, T mod)
{
    LLI ans = 1;
    LLI k = n;
    while(m)
    {
        if(m & 1)
        {
            ans *= k;
            if(ans>mod) ans %= mod;
        }
        k *= k;
        if(k>mod) k %= mod;
        m >>= 1;
    }
    return ans;
}
#define eps 1e-11
template<class T> string toString(T n)
{
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}
template<class T> string toBinary(T n)
{
    string ret="";
    while(n)
    {
        if(n%2==1)ret+='1';
        else ret+='0';
        n>>=1;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
void combination(int n,vector< vector<int> > &ret)
{
    ret.resize(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++)
    {
        ret[i][0]=ret[i][i]=1;
        for(int j=1; j<i; j++)
        {
            ret[i][j]=ret[i-1][j]+ret[i-1][j-1];
        }
    }
}
int toInt(string s)
{
    int r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
LLI toLInt(string s)
{
    LLI r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
double toDouble(string s)
{
    double r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}
vector<string> parse(string temp)
{
    vector<string> ans;
    ans.clear();
    string s;
    istringstream iss(temp);
    while (iss >> s)ans.PB(s);
    return ans;
}
template<class T> inline T gcd(T a, T b)
{
    if (a < 0)return gcd(-a, b);
    if (b < 0)return gcd(a, -b);
    return (b == 0) ? a : gcd(b, a % b);
}
template<class T> inline T lcm(T a, T b)
{
    if (a < 0)return lcm(-a, b);
    if (b < 0)return lcm(a, -b);
    return a*(b / gcd(a, b));
}
template<class T> inline T power(T b, T p)
{
    if (p < 0)return -1;
    if (b <= 0)return -2;
    if (!p)return 1;
    return b*power(b, p - 1);
}

template<class T> inline int asd(T &ret)
{
    char r;
    bool start=false,neg=false;
    ret=0;
    bool isaNumber=false;
    while(true)
    {
        r=getchar();
        if(r==EOF)
        {
            return 0;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start)
        {
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start)
        {
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(neg)
        ret*=-1;
    return 1;
}


template<class T> inline void asdasd(T x,char y)
{
    // 0- print+newline, 1 - print ' ',2 - nothing;
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    char buf[21], *p = buf;
    do
    {
        *p++ = '0' + x % 10;
        x /= 10;
    }
    while (x);
    do
    {
        putchar(*--p);
    }
    while (p > buf);
    if(y==0)putchar('\n');
    else if(y==1)putchar(' ');
}
#define filein(x) freopen(x,"r",stdin)
#define fileout(x) freopen(x,"w",stdout)
#define fst first
#define snd second
//istringstream(temp) >> data >> value >> stamp;
//mod1 = 1000000007, mod2 = 1000000009;
//.016-.040-.900-2.48
/***************************************************************************************************************************************/

VI V;

int main()
{
    int n;
    cin >> n;
    V.resize(n);
    for(int i=0;i<n;i++)
    {
        asd(V[i]);
    }
    SORT(V);
    V.resize(unique(all(V))-V.begin());
    int sz=V.size();
    int MX=0;
    for(int i=0;i<sz;i++)MX=max(MX,V[i]);
    MX*=2;
    int rs=0;
    for(int i=0;i<sz;i++)
    {
        for(int j=V[i]+V[i];j<=MX;j+=V[i])
        {
            int tmp=0;
            int need=j-1;
            int l=i+1,h=sz-1,m;
            while(h-l>1)
            {
                m=(l+h)>>1;
                if(V[m]>need)h=m-1;
                else l=m;
            }
            int x=i+1;
            for(x=min(h+2,sz-1);x>=max(i+1,l-2);x--)
            {
                if(V[x]<=need)break;
            }
            rs=max(rs,V[x]%V[i]);
        }
    }
    cout << rs << endl;
    return 0;
}
/*
6
3 4 5 6 7 8
*/




