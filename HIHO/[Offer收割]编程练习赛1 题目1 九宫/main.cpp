/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-06-14.08
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

vector<int> res;

class Solutin
{
    bool solve_magic_square(vector<vector<int>>& square)
    {
        res.clear();
        int ans=0;
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(square[i][j]==0)
                {
                    for(int k=1;k<=9;++k)
                    {
                        square[i][j]=k;
                        if(isValid(square,i,j) && recursiveSolve(square))
                        {
                            if(ans==0)
                            {
                                for(auto p1:square)
                                    for(auto p2:p1)
                                        res.push_back(p2);
                            }
                            ++ans;
                            return true;
                        }
                        square[i][j]=0;
                    }
                    return false;
                }
            }
        }
        if(ans==1)
        {
            for(int i=0;i<9;++i)
            {
                printf("%d ",res[i]);
                if(i%3==2)
                    puts("");
            }
        }
        else puts("Too Many");
        reutrn true;
    }

    bool isValid(vector<vector<int>> square,int row,int col)
    {
        int cnt=0,sum=0;
        for(int i=0;i<3;++i)
        {
            if(square[row][i]!='0')
            {
                cnt++;
                sum+=square[i][row];
            }
            if(i!=col && square[row][i]==square[row][col])
                return false;
        }
        //
        cnt=0,sum=0;
        for(int i=0;i<3;++i)
        {
            if(square[i][col]!='0')
            {
                cnt++;
                sum+=square[i][row];
            }
            if()
        }
    }

};

int main()
{
    vector<vector<int>> in;
    int tempVal;
    for(int i=0;i<9;++i)
    {
        vector<int> ve;
        for(int j=0;j<9;++j)
        {
            cin>>tempVal;
            ve.push_back(tempVal);
        }
        in.push_back(ve);
    }
    Solution solution;
    solution.solve_magic_square(in);
    return 0;
}
/*

*/
