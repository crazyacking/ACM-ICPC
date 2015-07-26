include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef double ll;
const double eps=1e-8;
struct Edge {
    int to, next;
} edge[10100];
int head[1010], cnt;

struct Point {
    ll x, y;
    ll dis2 ( Point one )
    {
        return sqrt(pow(x-one.x,2.0)+pow(y-one.y,2.0));
        //return ( x - one.x ) * ( x - one.x ) + ( y - one.y ) * ( y - one.y );
    }
} point[110];

int id[110];
string name[110];
vector<int> ans;
map<string, int>mp;
bool fire[110];
int n, m, sf;

void add ( int from, int to )
{
    edge[++cnt].to = to;
    edge[cnt].next = head[from];
    head[from] = cnt;
}

void maketp()
{
    queue<int> q;
    for ( int i = 1; i <= n; ++i ) {
        if ( fire[i] && id[i] == 0 ) {
            q.push ( i );
        }
    }
    int use = 0;
    int flag = 0;
    while ( !q.empty() ) {
        if ( q.size() > 1 ) flag = 1;
        int u = q.front();
        ++use;
        ans.push_back ( u );
        for ( int i = head[u]; i; i = edge[i].next ) {
            int v = edge[i].to;
            if ( --id[v] == 0 ) {
                q.push ( v );
            }
        }
        q.pop();
    }
    if ( use < sf ) {
        puts ( "IMPOSSIBLE");
    } else {
        if ( flag ) {
            puts ( "UNKNOWN" );
        } else {
            for ( int i = 0; i < ans.size(); ++i ) {
                cout << name[ans[i]];
                if ( i != ans.size() - 1 ) cout << " ";
                else cout << endl;
            }
        }
    }
}

void init()
{
    cnt = sf = 0;
    ans.clear();
    mp.clear();
    memset ( head, 0, sizeof ( head ) );
    memset ( id, 0, sizeof ( id ) );
    memset ( fire, 0, sizeof ( fire ) );
}
int main()
{
    int T;
    cin >> T;
    while ( T-- ) {
        init();
        cin >> n >> m;
        for ( int i = 1; i <= n; i++ ) {
            cin >> name[i];
            mp[name[i]] = i;
            cin >> point[i].x >> point[i].y;
        }
        while ( m-- ) {
            string s[6];
            for ( int i = 0; i < 6; i++ ) {
                cin >> s[i];
            }
            int a = mp[s[0]];
            int b = mp[s[2]];
            int c = mp[s[5]];
            if ( !fire[b] ) {
                ++sf;
                fire[b] = 1;
            }
            if ( !fire[c] ) {
                ++sf;
                fire[c] = 1;
            }
            if ( point[a].dis2 ( point[b] ) - point[a].dis2 ( point[c] )>eps ) {
                add ( b, c );
                id[c]++;
            }
        }
        maketp();
    }
    return 0;
}
