//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-21-15.38
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include <fstream>
#include<string>
#include<climits>
#include<cmath>
#define N 1000010
#define LL long long
#define M 100019169
#define B 100015724
using namespace std;
typedef long long ll;

void build (int a, int b, int c, vector <vector <bool> >& s, vector <vector <ll> >& t)
{
    t = vector <vector <ll> > (a - c + 1, vector <ll> (b));
    for (int i = 0; i < b; ++i)
    {
        t[0][i] = 0;
        for (int j = 0; j < c; ++j)
        {
            t[0][i] = (t[0][i] * B + int(s[j][i])) % M;
        }
    }
    ll tmp = 1;
    for (int i = 1; i < c; ++i)
    {
        tmp = (tmp * B) % M;
    }
    for (int k = 1; k <= a - c; ++k)
    {
        for (int i = 0; i < b; ++i)
        {
            t[k][i] = ((t[k - 1][i] - int(s[k - 1][i]) * tmp) * B + int(s[k + c - 1][i])) % M;
            t[k][i] = (t[k][i] + M) % M;
        }
    }
}

void buildTable(int b, vector <ll>& pattern, vector <int>& t)
{
    t = vector <int>(b);
    int i = 2, j = 0;
    t[0] = -1, t[1] = 0;
    while (i < b)
    {
        if (pattern[i - 1] == pattern[j])
        {
            t[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0) j = t[j];
        else
        {
            t[i] = 0;
            i++;
        }
    }

}

int KMP (int b, int d, vector <ll>& pattern, vector <ll>& image)
{
    int m = 0, i = 0, ret = 0;
    vector <int> t;
    buildTable(b, pattern, t);
    while (m + i < d)
    {
        if (pattern[i] == image[m + i])
        {
            i++;
            if (i == b)
            {
                ret++,i=0,m++;
            }
        }
        else
        {
            m += i - t[i];
            if (i > 0)
            {
                i = t[i];
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream cin_FILE;
    ofstream coutFILE;
    cin_FILE.open("input");
    coutFILE.open("output");
//    freopen("input1","r",stdin);
    int a, b, c, d;
    while (cin_FILE >> a >> b >> c >> d)
    {
        if (c < a || d < b)
        {
            cout << 0 << endl;
            continue;
        }
        vector <vector <bool> > small (a), big(c);
        vector <vector <ll> > pattern, image;
        for (int i = 0; i < a; ++i)
        {
            string s;
            cin_FILE >> s;
            for (int j = 0; j < b; ++j)
                small[i].push_back(s[j] == 'x');
        }
        for (int i = 0; i < c; ++i)
        {
            string s;
            cin_FILE >> s;
            for (int j = 0; j < d; ++j)
                big[i].push_back(s[j] == 'x');
        }
        // end input exchange
        int ans = 0;
        build(a, b, a, small, pattern);
        build(c, d, a, big, image);
        vector <vector <ll> >::iterator iter=image.begin();
        for (;iter!=image.end();++iter)
        {
            ans += KMP (b, d, pattern[0], *iter);
        }
        coutFILE << ans << endl;

    }

    return 0;
}
