#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        __init(n);
        dfs(0,n,mat);
        return res;
    }
    void dfs(int row,int n,vector<string> &mat)
    {
        if(row==n)
        {
            res.push_back(mat);
            return ;
        }
        for(int col=0; col<n; ++col)
        {
            if(check(mat,row,col,n))
            {
                mat[row][col]='Q';
                dfs(row+1,n,mat);
                mat[row][col]='.';
            }
        }
    }

    bool check(vector<string> &mat,int row,int col,int n)
    {
        // up
        for(int i=0; i<row; ++i)
            if(mat[i][col]=='Q')
                return false;
        // left,up
        for(int i=row-1,j=col-1;i>=0 && j>=0;--i,--j)
            if(mat[i][j]=='Q')
                return false;
        // right,up
        for(int i=row-1,j=col+1;i>=0 && j<n;--i,++j)
            if(mat[i][j]=='Q')
                return false;
        return true;
    }
    void __init(int n)
    {
        res.clear();
        mat=*(new vector<string>(n,string(n,'.')));
    }
private:
    vector<string> mat;
    vector<vector<string>> res;
};

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        vector<vector<string>> res=solution.solveNQueens(n);
        for(vector<vector<string>>::iterator it1=res.begin(); it1!=res.end(); ++it1)
        {
            for(vector<string>::iterator it2=(*it1).begin(); it2!=(*it1).end(); ++it2)
                cout<<*it2<<endl;
            cout<<"------------------------------"<<endl;
        }
    }
    return 0;
}


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

// first submition
// please ignore my code,it just like a shit

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        __init(n);
        dfs(0,n,mat,0);
        return res;
    }
    void dfs(int num,int n,vector<string> &mat,int queen)
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
            dfs(num+1,n,mat,queen+1);
            mat[row][col]='.';
        }
        mat[row][col]='.';
        dfs(num+1,n,mat,queen);
    }

    bool check(vector<string> &mat,int row,int col,int n)
    {
        for(int i=0; i<n; ++i)
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
        res.clear();
        mat=*(new vector<string>(n,string(n,'.')));
    }
private:
    vector<string> mat;
    vector<vector<string>> res;
};

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        vector<vector<string>> res=solution.solveNQueens(n);
        for(vector<vector<string>>::iterator it1=res.begin(); it1!=res.end(); ++it1)
        {
            for(vector<string>::iterator it2=(*it1).begin(); it2!=(*it1).end(); ++it2)
                cout<<*it2<<endl;
            cout<<"------------------------------"<<endl;
        }
    }
    return 0;
}


class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, int row, int &n)
    {
        if (row == n)
        {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n))
            {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(vector<string> &nQueens, int row, int col, int &n)
    {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45бу diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135бу diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        __init(n);
        dfs(0,n,mat);
        return res;
    }
    void dfs(int row,int n,vector<string> &mat)
    {
        if(row==n)
        {
            res.push_back(mat);
            return ;
        }
        for(int col=0; col<n; ++col)
        {
            if(check(mat,row,col,n))
            {
                mat[row][col]='Q';
                dfs(row+1,n,mat);
                mat[row][col]='.';
            }
        }
    }

    bool check(vector<string> &mat,int row,int col,int n)
    {
        // up
        for(int i=0; i<row; ++i)
            if(mat[i][col]=='Q')
                return false;
        // left,up
        for(int i=row-1,j=col-1;i>=0 && j>=0;--i,--j)
            if(mat[i][j]=='Q')
                return false;
        // right,up
        for(int i=row-1,j=col+1;i>=0 && j<n;--i,++j)
            if(mat[i][j]=='Q')
                return false;
        return true;
    }
    void __init(int n)
    {
        res.clear();
        mat=*(new vector<string>(n,string(n,'.')));
    }
private:
    vector<string> mat;
    vector<vector<string>> res;
};

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        vector<vector<string>> res=solution.solveNQueens(n);
        for(vector<vector<string>>::iterator it1=res.begin(); it1!=res.end(); ++it1)
        {
            for(vector<string>::iterator it2=(*it1).begin(); it2!=(*it1).end(); ++it2)
                cout<<*it2<<endl;
            cout<<"------------------------------"<<endl;
        }
    }
    return 0;
}


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

// first submition
// please ignore my code,it just like a shit

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        __init(n);
        dfs(0,n,mat,0);
        return res;
    }
    void dfs(int num,int n,vector<string> &mat,int queen)
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
            dfs(num+1,n,mat,queen+1);
            mat[row][col]='.';
        }
        mat[row][col]='.';
        dfs(num+1,n,mat,queen);
    }

    bool check(vector<string> &mat,int row,int col,int n)
    {
        for(int i=0; i<n; ++i)
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
        res.clear();
        mat=*(new vector<string>(n,string(n,'.')));
    }
private:
    vector<string> mat;
    vector<vector<string>> res;
};

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        vector<vector<string>> res=solution.solveNQueens(n);
        for(vector<vector<string>>::iterator it1=res.begin(); it1!=res.end(); ++it1)
        {
            for(vector<string>::iterator it2=(*it1).begin(); it2!=(*it1).end(); ++it2)
                cout<<*it2<<endl;
            cout<<"------------------------------"<<endl;
        }
    }
    return 0;
}


class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > res;
        vector<string> nQueens(n, string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private:
    void solveNQueens(vector<vector<string> > &res, vector<string> &nQueens, int row, int &n)
    {
        if (row == n)
        {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n))
            {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    bool isValid(vector<string> &nQueens, int row, int col, int &n)
    {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45бу diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135бу diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};
