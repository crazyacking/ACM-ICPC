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

