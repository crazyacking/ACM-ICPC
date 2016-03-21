/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-02-18.53
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
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

class Solution
{
public:
    void solveSudoku(vector<vector<char>>& board)
    {
        recursiveSolve(board);
    }

    bool recursiveSolve(vector<vector<char>>& board)
    {
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(board[i][j]=='.')
                {
                    for(int k=1; k<=9; ++k)
                    {
                        board[i][j]=static_cast<char>(k+'0');
                        if(isValid(board,i,j) && recursiveSolve(board))
                            return true;
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(const vector<vector<char>>& board,const int r1,const int c1)const
    {
        for(int i=0; i<9; ++i)
        {
            if(i!=r1 && board[i][c1]==board[r1][c1])
                return false;
            if(i!=c1 && board[r1][i]==board[r1][c1])
                return false;
        }
        int rowBegin=r1/3*3;
        int colBegin=c1/3*3;
        for(int i=rowBegin; i<rowBegin+3; ++i)
        {
            for(int j=colBegin; j<colBegin+3; ++j)
            {
                if(i!=r1 && j!=c1 && board[i][j]==board[r1][c1])
                    return false;
            }
        }
        return true;
    }
};


int main()
{
    freopen("H:\\Code_Fantasy\\in.txt","r",stdin);
    Solution solution;
    vector<vector<char>> ve;
    string s;
    while(cin>>s)
    {
        vector<char> tempVe;
        for(int i=0; i<s.length(); ++i)
            tempVe.push_back(s[i]);
        ve.push_back(tempVe);
    }
    solution.solveSudoku(ve);
    return 0;
}
/*

*/
