/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-05-22-09.27
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


#define fd(i,n) for(int i=(n)-1; i>=0; i--)
#define fa(i,x) fu(i,(x).begin(),(x).end())

#define i64 long long
using namespace std;

struct PlayingCubes
{
    vector <int> composeWords(vector <string> c, vector <string> w)
    {
        sort(c.begin(),c.end());
        vector<int> ret;
        for(int i=0; i<w.size(); ++i)
        {
            sort(c.begin(),c.end());
            bool g=0;
            do
            {
                if(w[i].size()>c.size()) continue;
                bool cur=1;
                for(int j=0;j<w[i].size();++j) if(c[j].find(w[i][j])==-1) cur=0;
                if(cur) g=1;
            }
            while(next_permutation(c.begin(),c.end()));
            if(g) ret.push_back(i);
        }
        return ret;
    }
};

int main()
{
    int n,m;
    while(cin>>n)
    {
        vector<string> cubes(n);
        string s;
        for(int i=0; i<n; ++i)
        {
            cin>>s;
            cubes[i]=s;
        }
        cin>>m;
        vector<string> words(m);
        for(int i=0; i<m; ++i)
        {
            cin>>s;
            words[i]=s;
        }
        PlayingCubes pc;
        vector <int> ans=pc.composeWords(cubes,words);
        for(int i=0; i<ans.size(); ++i)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
/*

*/
