#include <bits/stdc++.h>
using namespace std;


#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)



////////////////////////////////////////////////////////////
struct Coin
{
    int v,a,b;
};



struct CoinWeight
{
    // MAIN
    int possibleValues(int weight, vector<string> &cc)
    {
        vector<set<int> > poss(weight+1);
        vector<Coin> coins(cc.size());
        REP(i,cc.size())
        {
            istringstream is(cc[i]);
            is >> coins[i].v >> coins[i].a >> coins[i].b;
        }
        poss[0].insert(0);
        FOR(w,1,weight)
        {
            for(vector<Coin>::iterator it=coins.begin(); it!=coins.end(); ++it)
                FOR(wc,it->a,it->b)
            {
                if(wc<=w)
                {
                    set<int> &ss = poss[w-wc];
                    set<int> &ss2 = poss[w];
                    for(set<int>::iterator it2=ss.begin(); it2!=ss.end(); ++it2)
                        ss2.insert(*it2 + it->v);
                }
            }
        }
        return poss[weight].size();
    }
};

int main()
{
//    ifstream fin("H:\\Code_Fantasy\\parser-tool\\output\\1.in");
    int weight;
    while(cin>>weight)
    {
        cout<<weight<<endl;
        int num;
        cin>>num;
//        getchar();
        vector<string> coins(num);
        for(int i=0; i<num; ++i)
            getline(cin,coins[i]);
        CoinWeight cw;
        int ans=cw.possibleValues(weight,coins);
        cout<<ans<<endl;
    }
    return 0;
}
