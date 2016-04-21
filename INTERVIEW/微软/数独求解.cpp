#include <bits/stdc++.h>
using namespace std;
/**< 记录一下微软电面的代码，写得太搓啦 :(  */

class Solve_Shudu
{
public:
    void solve(vector<vector<char> > &matrix)
    {
        is_solve=0;
        for(int i=0; i<10; ++i)
        {
            for(int j=0; j<10; ++j)
                col[i][j]=row[i][j]=b[i][j]=0;
        }
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(!(matrix[i][j]>='0' && matrix[i][j]<='9'))
                    continue;
                int board_num=(i/3)*3+j/3;
                int num=matrix[i][j]-'0';
                col[j][num]=row[i][num]=b[board_num][num]=1;
            }
        }
        dfs(matrix,0,0);
    }
    void dfs(vector<vector<char> > &matrix,int x,int y)
    {
        if(is_solve) return;
        if(x>=9)
        {
            is_solve=true;
            return ;
        }
        if(matrix[x][y]!='.')
        {
            if(y<8)
                dfs(matrix,x,y+1);
            else  dfs(matrix,x+1,0);
            if(is_solve) return;
        }
        else
        {
            int tmp=(x/3)*3 + y/3;
            for(int num=1; num<=9; ++num)
            {
                if((!col[x][num])&&
                        (!row[x][num])&&
                        (!b[tmp][num]))
                {
                    matrix[x][y]=num+'0';
                    col[y][num]=row[x][num]=b[tmp][num]=1;
                    if(y<8)
                        dfs(matrix,x,y+1);
                    else dfs(matrix,x+1,0);
                    col[y][num]=row[x][num]=b[tmp][num]=0;
                    if(is_solve) return;
                }
            }
            matrix[x][y]='.';
        }
    }
private:
    bool col[10][10],row[10][10],b[10][10];
    bool is_solve;
};

int main()
{
    vector<vector<char> > mat(9,vector<char>(9));
    while(1)
    {
        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
                cin>>mat[i][j];
        }
        Solve_Shudu solve;
        solve.solve(mat);
        // print result...
    }
    return 0;
}
