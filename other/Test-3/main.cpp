/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-09-11.08
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

const int MAXN=10010;

class Solution
{
public:
    int find(int x)
    {
        return x!=parents[x]?parents[x]=find(parents[x]):x;
    }

    void init()
    {
        for(int i=0; i<MAXN; ++i)
        {
            parents[i]=i;
            isLeaf[i]=true;
        }
    }

    void create_relationship(int a,int b,int c)
    {
        parents[find(b)]=a;
        parents[find(c)]=a;
    }

    void judge()
    {
        int x;
        for(int i=0; i<MAXN; ++i)
        {
            if(parents[i]!=i)
            {
                x=find(i);
                isLeaf[x]=false;
            }
        }
    }

    void query(int m)
    {
        for(int i=0; i<MAXN; ++i)
        {
            if(find(i)==m && isLeaf[i]==true)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
        cout<<"-------------------"<<endl;
    }

private:
    int parents[MAXN];
    bool isLeaf[MAXN];

};

int main()
{
    int n;
    Solution solution;
    while(cin>>n)
    {
        solution.init();
        int a,b,c;
        for(int i=0; i<n; ++i)
        {
            cin>>a>>b>>c;
            solution.create_relationship(a,b,c);
        }
        solution.judge();
        int m;
        cin>>m;
        solution.query(m);
    }

    return 0;
}
