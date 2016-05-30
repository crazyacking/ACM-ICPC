#include <bits/stdc++.h>
using namespace std;

map<long long, int> seen;
int sz;
long long goal;
long long bp, np;
//int doit(long long s)
//{
//    if( s == goal || !s ) return 0;
//    int &ret = seen[s];
//    if( ret ) return ret;
//    ret = -1;
//    s = (s<<1) + (s>>(sz-1));
//    int ret1 = doit(s&bp);
//    if( ret1 == -1 ) return -1;
//    int ret2 = doit(s&np);
//    if( ret2 == -1 ) return -1;
//    return ret = max(ret1 , ret2) + 1;
//}
//
//class SimpleIO
//{
//public:
//    int worstCase(string pattern, int targetState)
//    {
//        sz = pattern.size();
//        int i, j, k, x, y, z, n;
//        for( i = 0; i < pattern.size(); i++ )
//            if( pattern[i] == 'B' )
//                bp += (1ll<<i);
//            else
//                np += (1ll<<i);
//        goal = (1ll<<targetState);
//        return doit((1ll<<pattern.size())-1);
//    }
//};




class SimpleIO
{
    int pre(int idx, int len)
    {
        int res = idx - 1;
        if (res < 0) res = len - 1;
        return res;
    }
public:
    int worstCase(string pattern, int targetState)
    {
        int len = pattern.length();
        set<long long> mm;
        for (int i = 0; i < len; i++)
        {
            long long t = 0;
            for (int j = 0, idx = i; j < len; j++)
            {
                t = t * 2 + (pattern[idx] == 'B' ? 1 : 0);
                idx++;
                if (idx == len) idx = 0;
            }
            if (mm.find(t) != mm.end()) return -1;
            mm.insert(t);
        }
        int _max = 0, idx = targetState;
        for (int k = 0; k + 1 < len; k++)
        {
            idx = pre(idx, len);
            int t = targetState, cnt = 0, tIdx = idx;
            //can always end
            while (pattern[t] == pattern[tIdx])
            {
                cnt++;
                tIdx = pre(tIdx, len);
                t = pre(t, len);
            }
            _max = max(_max, cnt);
        }
        return _max + len;
    }
};


int main()
{
    string s;
    while(cin>>s)
    {
        int n;
        cin>>n;
        SimpleIO si;
        int ans=si.worstCase(s,n);
        cout<<ans<<endl;

    }
    return 0;
}
/*

*/
