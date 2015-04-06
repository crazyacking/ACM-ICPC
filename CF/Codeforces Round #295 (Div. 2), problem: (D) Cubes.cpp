#include <iostream>
#include<memory.h>
#include <map>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

/*
*/

int main()
{
    int m;
    cin>>m;
    vector<pair<int, int> > c(m);
    map<pair<int, int> , int > mp;
    vector<int> stability(m);
    for (int i = 0; i < m; i++) {
        cin>>c[i].first>>c[i].second;
        mp[c[i]] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int st = 0;
        pair<int, int> under = make_pair(c[i].first, c[i].second - 1);
        if (c[i].second == 0) stability[i] = 10000000;
        else
        {
            if (mp.count(under) > 0) st++;
            under.first++;
            if (mp.count(under) > 0) st++;
            under.first-=2;
            if (mp.count(under) > 0) st++;
            stability[i] = st;
        }
    }
    set<int> ok;
    long long r = 0;
    for (int i = 0; i < m; i++)
    {
        pair<int, int> under = make_pair(c[i].first-1, c[i].second + 1);
        if (mp.count(under) && stability[mp[under]] == 1) continue;
        under.first++;
        if (mp.count(under) && stability[mp[under]] == 1) continue;
        under.first++;
        if (mp.count(under) && stability[mp[under]] == 1) continue;
        ok.insert(i);
    }
    vector<bool> done(m, false);
    for (int i = 0; i < m; i++)
    {
        int in;
        set<int> ::iterator it;
        if (i%2==0)
        {
            it = ok.end();
            it--;
            in = (*it);
        }
        else
        {
            it = ok.begin();
            in = (*it);
        }
        r*=m;
        r+= in;
        r%= 1000000009;
        done[in] = true;
        ok.erase(in);
        for (int j = c[in].first-1; j <= c[in].first + 1; j++)
        {
            int in2;
            if (mp.count(make_pair(j, c[in].second+1)))
                in2 = mp[make_pair(j, c[in].second+1)];
            else
                continue;
            if (done[in2]) continue;
            stability[in2]--;
            if (stability[in2] > 1) continue;
            for (int k = c[in2].first-1; k <= c[in2].first + 1; k++)
            {
                int in3;
                if (mp.count(make_pair(k, c[in].second))) in3 = mp[make_pair(k, c[in].second)];
                else continue;
                if (ok.count(in3)) ok.erase(in3);
            }
        }
        
        for (int j = c[in].first-1; j <= c[in].first + 1; j++)
        {
            int in2;
            if (mp.count(make_pair(j, c[in].second-1)))
                in2 = mp[make_pair(j, c[in].second-1)];
            else
                continue;
            if (done[in2]) continue;
            bool notyet = false;
            for (int k = c[in2].first-1; k <= c[in2].first + 1; k++)
            {
                int in3;
                if (mp.count(make_pair(k, c[in].second))) in3 = mp[make_pair(k, c[in].second)];
                else continue;
                if (!done[in3] && stability[in3] < 2) notyet = true;
            }
            if (!notyet) ok.insert(in2);
        }
    }
    cout<<r<<endl;
}
