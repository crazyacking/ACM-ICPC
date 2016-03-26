/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-21-13.13
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

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if(matrix.size()==0)
            return res;
        int n=matrix.size(),m=matrix[0].size();
        int l=0,r=m-1,u=0,d=n-1;
        while(true)
        {
            for(int col=l;col<=r;++col)
                res.push_back(matrix[u][col]);
            if(++u>d) break;

            for(int row=u;row<=d;++row)
                res.push_back(matrix[row][r]);
            if(--r<l) break;

            for(int col=r;col>=l;--col)
                res.push_back(matrix[d][col]);
            if(--d<u) break;

            for(int row=d;row>=u;--row)
                res.push_back(matrix[row][l]);
            if(++l>r) break;
        }
        return res;
    }
};

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
                cin>>mat[i][j];
        }
        Solution solution;
        auto ans=solution.spiralOrder(mat);
        for(auto p:ans)
            cout<<p<<" ";
        cout<<endl;
        cout<<"---------------------------------"<<endl;
    }
    return 0;
}
/*
54. Spiral Matrix My Submissions Question
Total Accepted: 55063 Total Submissions: 247261 Difficulty: Medium
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

*/
