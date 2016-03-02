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
        checkResult(board);
    }

    //=====================
    bool recursiveSolve(vector<vector<char>>& board)
    {
        unordered_map<char,bool> rowMap;
        unordered_map<char,bool> colMap;
        unordered_map<char,bool> blockMap;
        int row=board.size();
        int col=board[0].size();
        int r1=0,c1=0;
        bool isFinished=true;
        for(r1=0;r1<row;++r1)
        {
            for(c1=0;c1<col;++c1)
            {
                if(board[r1][c1]=='.')
                {
                    isFinished=false;
                    break;
                }
            }
            if(!isFinished)
                break;
        }
        Sleep(150);
        cout<<"point="<<r1<<" "<<c1<<endl;

        if(isFinished)
        {
            puts("===============================Program Run Here !=============================");
            return true;
        }

        for(int i=0;i<9;++i)
        {
            if(board[r1][i]!='.')
            {
                if(rowMap.count(board[r1][i])>0)
                    return false;
                rowMap[board[r1][i]]=true;
            }
            if(board[i][c1]!='.')
            {
                if(colMap.count(board[i][c1])>0)
                    return false;
                colMap[board[i][c1]]=true;
            }
        }

        int staRow=r1/3*3;
        int staCol=c1/3*3;
//        cout<<staRow<<" "<<staCol<<endl;
        for(int i=staRow;i<staRow+3;++i)
        {
            for(int j=staCol;j<staCol+3;++j)
            {
                if(board[i][j]!='.')
                {
                    if(blockMap.count(board[i][j])>0)
                        return false;
                    blockMap[board[i][j]]=true;
                }
            }
        }


        for(int num=1;num<=9;++num)
        {
            char ch=static_cast<char>(num+'0');
            if(rowMap.count(ch)==0 && colMap.count(ch)==0 && blockMap.count(ch)==0)
            {
                board[r1][c1]=ch;
                if(recursiveSolve(board))
                {
                    puts("===hehe============");
                    break;
                }
                board[r1][c1]='.';
            }
        }


        if(isFinished)
            return true;
        else
            return false;
    }

    void checkResult(vector<vector<char>>& board)
    {
        puts("======================================================");
        for(auto p1:board)
        {
            for(auto p2:p1)
                cout<<p2<<" ";
            cout<<endl;
        }
        puts("======================================================");
    }

};

void output(vector<vector<char>>& ve)
{
    for(auto p1:ve)
    {
        for(auto p2:p1)
            cout<<p2<<" ";
        cout<<endl;
    }
}

int main()
{
    freopen("H:\\Code_Fantasy\\in.txt","r",stdin);
    Solution solution;
    vector<vector<char>> ve;
    string s;
    while(cin>>s)
    {
        vector<char> tempVe;
        for(int i=0;i<s.length();++i)
            tempVe.push_back(s[i]);
        ve.push_back(tempVe);
    }
    output(ve);
    solution.solveSudoku(ve);
    return 0;
}
/*

*/
