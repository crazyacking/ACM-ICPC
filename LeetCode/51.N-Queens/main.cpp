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
        solve(matrix,res,n,0);
        output(res);
        return res;
    }

    void solve(auto& matrix,auto& res,int n,int pos)
    {
        if(pos==n*n)
        {
            res.push_back(matrix);
            return ;
        }
        for(int i=pos;i<n*n;++i)
        {
             matrix[i/n][i%n]='Q';
             if(is_ok(matrix,i,n))
                solve(matrix,res,n,pos+1);
             matrix[i/n][i%n]='.';
        }
    }


    bool is_ok(auto& matrix,int pos,int n)
    {
         int row=pos/n,col=pos%n;
         // heng
         for(int i=0;i<n;++i)
             if(matrix[row][i]=='Q' && i!=col)
                 return false;

        // shu
        for(int i=0;i<n;++i)
            if(matrix[i][col]=='Q' && i!=row)
                return false;
        // zuo shang
        int r=row,c=col;
        while(r && c)
        {
             --r,--c;
        }
        for(int i=r;i<n;++i)
        {
            for(int j=c;j<n;++j)
            {
                if(matrix[i][j]=='Q' && (!(i==row && j==col)))
                    return false;
            }
        }
        // you shang
        r=row,c=col;
        while(r && c<n-1)
        {
             --r,++c;
        }
        for(int i=r;i<n;++i)
        {
            for(int j=c;j>=0;--j)
            {
                if(matrix[i][j]=='Q' && (!(i==row && j==col)))
                    return false;
            }
        }
        return true;
    }

    void output(auto& res)
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
