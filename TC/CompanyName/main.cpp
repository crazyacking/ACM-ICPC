#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//#define forIter(I,C) for(typeof((C).end()) I=(C).begin(); I!=(C).end(); ++I)
typedef vector<string> VS;

struct CompanyName
{
    bool isVowel(char c)
    {
        return strchr("AaEeIiOoUu", c) != 0;
    }
    int getScore(const string& s)
    {
        int ret = 0;
        int v = 0, c = 0;
//        forIter ( i, s )
        for(auto i:s)
        {
            if ( isVowel(i) )
            {
                if ( c )
                {
                    ret += 2*c-1;
                    c = 0;
                }
                ++v;
            }
            else
            {
                if ( v )
                {
                    ret += 1;
                    v = 0;
                }
                ++c;
            }
        }
        if ( c )
        {
            ret += 2*c-1;
            c = 0;
        }
        if ( v )
        {
            ret += 1;
            v = 0;
        }
        return ret;
    }
    string shortestProposal(VS proposals)
    {
        string ret;
        int best = -1;
        for(auto i:proposals)
        {
            int s = getScore(i);
            if ( best < 0 || s < best )
            {
                best = s;
                ret = i;
            }
        }
        return ret;
    }
};

int main()
{
//    freopen("G:\\nowcoder\\1.in","r",stdin);
//    freopen("G:\\nowcoder\\1.out","w",stdout);
    int n;
    while(cin>>n)
    {
        vector<string> vs(n);
        for(int i=0;i<n;++i)
        {
            cin>>vs[i];
        }
        CompanyName cn;
        string ans=cn.shortestProposal(vs);
        cout<<ans<<endl;
    }
    return 0;
}
/*
aaa AAa aaA AAA AaA Aaa
*/
