/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-06-12.02
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

void wiggleSort(vector<int>& nums)
{
    int n = nums.size();
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());

    int mid = *midptr;

#define A(i) nums[(1+2*(i)) % (n|1)]
    // Dutch_National_Flag_Problem
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        if (A(j) > mid)
            swap(A(i++),A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
}


int main()
{
    freopen("D:\\Desktop\\in.txt","r",stdin);
    vector<int> a;
    int n;
    while(cin>>n)
    {
        a.clear();
        for(int i=0; i<n; ++i)
        {
            int tmp;
            cin>>tmp;
            a.push_back(tmp);
        }
        wiggleSort(a);
        for(auto p:a)
            cout<<p<<" ";
        cout<<endl;
    }
    return 0;
}
