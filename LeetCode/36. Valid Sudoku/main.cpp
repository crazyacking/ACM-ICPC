/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-02-18.28
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
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int row=board.size();
        int col=board[0].size();
        set<int> se;
        // -------
        for(int i=0;i<row;++i)
        {
            se.clear();
            for(int j=0;j<col;++j)
                if(board[i][j]!='.')
                {
                    int k=board[i][j]-'0';
                    if(se.count(k))
                        return false;
                    se.insert(k);
                }
        }
        // -------
        for(int i=0;i<col;++i)
        {
            se.clear();
            for(int j=0;j<row;++j)
                if(board[j][i]!='.')
                {
                    int k=board[j][i]-'0';
                    if(se.count(k))
                        return false;
                    se.insert(k);
                }
        }
        //*****
        for(int i=0;i<row-2;i+=3)
        {
            for(int j=0;j<col-2;j+=3)
                if(!checkBoard(board,i,j))
                    return false;
        }
        return true;
    }

    bool checkBoard(vector<vector<char>>& board,int bi,int bj)
    {
        set<int> se;
        for(int i=bi;i<bi+3;++i)
        {
            for(int j=bj;j<bj+3;++j)
            {
                if(board[i][j]!='.')
                {
                    int k=board[i][j]-'0';
                    if(se.count(k))
                        return false;
                    se.insert(k);
                }
            }
        }
        return true;
    }
};

int main()
{
    freopen("H:\\Code_Fantasy\\in.txt","r",stdin);
    vector<vector<char>> ve;
    string s;
    while(cin>>s)
    {
        vector<char> tempVe;
        for(int i=0;s[i];++i)
        {
            tempVe.push_back(s[i]);
        }
        ve.push_back(tempVe);
    }
    Solution solution;
    bool ans=solution.isValidSudoku(ve);
    puts(ans?"true":"false");
    return 0;
}
/*

*/
