/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-21-11.01
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
    int totalNQueens(int n)
    {
        ans=0;
        mat=*new vector<string>(n,string(n,'.'));
        dfs(mat,0,n);
        return ans;
    }
    void dfs(vector<string> &mat,int row,int n)
    {
        if(row==n)
            {ans++; return;}
        for(int col=0;col<n;++col)
        {
            if(check(row,col,mat,n))
            {
                mat[row][col]='Q';
                dfs(mat,row+1,n);
                mat[row][col]='.';
            }
        }
    }

    bool check(int row,int col,vector<string> &mat,int n)
    {
        for(int i=0;i<row;++i)
            if(mat[i][col]=='Q')
                return 0;
        for(int x=row-1,y=col-1;x>=0 && y>=0;--x,--y)
            if(mat[x][y]=='Q')
                return 0;
        for(int x=row-1,y=col+1;x>=0 && y<n;--x,++y)
            if(mat[x][y]=='Q')
                return 0;
        return 1;
    }

private:
    int ans;
    vector<string> mat;
};

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        int ans=solution.totalNQueens(n);
        cout<<ans<<endl;
        cout<<"------------------------------"<<endl;
    }
    return 0;
}
/*

*/
