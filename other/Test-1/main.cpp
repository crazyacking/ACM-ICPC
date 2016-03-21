#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > res;
        vector<string> matrix(n);
        string str(n,'.');
        for(int i=0;i<n;++i)
            matrix[i]=str;

        solve(matrix,res,n,0,0);
        output(res);
        return res;
    }

    void solve(vector<string>& matrix,vector<vector<string> >& res,int& n,int row,int col)
    {
        if(row=n-1 && col==n-1)
        {
            res.push_back(matrix);
            return ;
        }

        for(int i=row;i<n;++i)
        {
            for(int j=col;j<n;++j)
            {
                 matrix[i][j]='Q';
            }
        }

    }

    void output(vector<vector<string>> res)
    {
        for(auto p1:res)
        {
            for(auto p2:p1)
            {
                 cout<<p2<<endl;
            }
            cout<<" ----------------------------"<<endl;
        }
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        solution.solveNQueens(n);
    }
    return 0;
}
