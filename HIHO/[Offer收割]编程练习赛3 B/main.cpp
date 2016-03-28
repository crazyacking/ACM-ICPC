/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-27-14.29
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

long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}

const int NN=100010000;
bool v[NN];
int p[NN];
void makePrime()
{
      int num=-1,i,j;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
      //cout<<num<<endl;
}


LL get_num(long long x)
{
    LL res=1;
    int idx=0;
    while(x>=p[idx])
    {
        int cnt=0;
        while(x%p[idx]==0)
        {
            x/=p[idx];
            ++cnt;
        }
        ++idx;
        if(idx>=NN) break;
        res*=(cnt+1);
    }
    return res;
}

int main()
{
    makePrime();
    long long n,m;
    while(cin>>n>>m)
    {
        long long g=gcd(n,m);
        long long n1=get_num(n);
        long long n2=get_num(m);
        long long ng=get_num(g);
        int ggcd=gcd(n1*n2,ng);

        cout<<n1*n2/ggcd<<" "<<ng/ggcd<<endl;
    }
    return 0;
}
/*

*/
