/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-20-16.35
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
    vector<vector<string>> solveNQueens(int n)
    {
        __init(n);
        vector<vector<string>> res;
        dfs(0,n,mat,res,0);
        return res;
    }
    void dfs(int num,int n,vector<string> &mat,vector<vector<string>> &res,int queen)
    {
        if(num==n*n)
        {
            if(queen==n)
                res.push_back(mat);
            return ;
        }
        int row=num/n;
        int col=num%n;
        if(check(mat,row,col,n))
        {
            mat[row][col]='Q';
            dfs(num+1,n,mat,res,queen+1);
        }
        mat[row][col]='.';
        dfs(num+1,n,mat,res,queen);
    }

    bool check(vector<string> &mat,int row,int col,int n)
    {
        for(int i=0;i<n;++i)
        {
            if((mat[row][i]=='Q' && i!=col) || (mat[i][col]=='Q' && i!=row))
                return false;
        }
        // left,up
        int x=row,y=col;
        while(x && y) --x,--y;
        while(x<n && y<n)
        {
            if(mat[x][y]=='Q' && (!(x==row && y==col)))
                return false;
            ++x,++y;
        }
        // right,up
        x=row,y=col;
        while(x && (y<n-1)) --x,++y;
        while(x<n && y)
        {
            if(mat[x][y]=='Q' && (!(x==row && y==col)))
                return false;
            ++x,--y;
        }
        return true;
    }
    void __init(int n)
    {
        string res(n,'.');
        mat=*(new vector<string>(n,res));
    }
private:
    vector<string> mat;
};

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        vector<vector<string>> res=solution.solveNQueens(n);
        for(vector<vector<string>>::iterator it1=res.begin();it1!=res.end();++it1)
        {
            for(vector<string>::iterator it2=(*it1).begin();it2!=(*it1).end();++it2)
                cout<<*it2<<endl;
            cout<<"------------------------------"<<endl;
        }
    }
    return 0;
}
