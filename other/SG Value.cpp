//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-29-18.44
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define MAXN 1000010
#define LL long long
using namespace std;

priority_queue<LL,vector<LL>,greater<LL> > q;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
//      freopen("C:\\Users\\Devin\\Desktop\\cin.cpp","r",stdin);
//      freopen("C:\\Users\\Devin\\Desktop\\cout.cpp","w",stdout);
        LL t;
        while(cin>>t)
        {
                LL v=0;// biggest num
                while(!q.empty()) q.pop();
                while(t--)
                {
                        LL type;
                        cin>>type;
                        if(type==1) // insert
                        {
                                LL num;
                                cin>>num;
                                if(num>v+1)
                                {
                                        q.push(num);
                                }
                                else
                                {
                                        v+=num;
                                        while(!q.empty())
                                        {
                                                LL tmp=q.top();
                                                if(tmp<=v+1)
                                                {
                                                        v+=tmp;
                                                        q.pop();
                                                }
                                                else break;
                                        }
                                }
                        }
                        else cout<<v+1<<endl;
                }
        }
        return 0;
}
/*

*/

/**************************************************************
    Problem: 1554
    User: crazyacking
    Language: C++
    Result: Accepted
    Time:396 ms
    Memory:1996 kb
****************************************************************/
