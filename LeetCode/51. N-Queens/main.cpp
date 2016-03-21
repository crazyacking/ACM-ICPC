#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;
        dfs(0,n,mat,res,0);
        return res;
    }
    void dfs(int num,int n,auto &mat,auto &res,int queen)
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
//        dfs(num+1,n,mat,res);
//        else
//        {
//            mat[row][col]='.';
//            dfs(num+1,n,mat,res);
//        }
    }

    bool check(auto mat,int row,int col,int n)
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
    Solution(int n)
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
        Solution solution(n);
        auto res=solution.solveNQueens(n);
        for(auto p1:res)
        {
            for(auto p2:p1)
                cout<<p2<<endl;
            cout<<"------------------------------"<<endl;
        }
        cout<<"------------------------------"<<endl;
    }
    return 0;
}
