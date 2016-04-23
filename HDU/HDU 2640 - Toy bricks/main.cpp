#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	return 0;
}

/* - TLE code - */
// #include <iostream>
// using namespace std;
//
// const int max_row = 110;
// const int max_col = 110;
// int row, col;
// char box[max_row][max_col];
//
// int dx[4] = {1, 0, -1, 0};
// int dy[4] = {0, 1, 0, -1};
// class Solution
// {
// public:
// 	int play_block()
// 	{
// 		ans = -(1 << 30);
// 		dfs(0,0,0);
// 		return ans;
// 	}
//
// 	inline void dfs(int x, int y, int res)
// 	{
// 		ans = max(ans, res);
// 		if (x >= row)
// 			return;
// 		for (int i = x; i < row; ++i)
// 		{
// 			for (int j = y; j < col; ++j)
// 			{
// 				if (box[i][j] == '.' && check(i, j))
// 				{
// 					// cout<<"passed check"<<endl;
// 					mark(i, j);
// 					if (y + 1 < col)
// 						dfs(x, y + 1, res + 1);
// 					else
// 						dfs(x + 1, 0, res + 1);
// 					mark(i, j);
// 				}
// 			}
// 		}
// 	}
//
// 	inline bool check(int x, int y)
// 	{
// 		if (!(x - 1 >= 0 && x + 1 < row && y - 1 >= 0 && y + 1 < col))
// 			return false;
// 		for (int i = 0; i < 4; ++i)
// 		{
// 			int xx = x + dx[i];
// 			int yy = y + dy[i];
// 			if (box[xx][yy] != '.')
// 				return false;
// 		}
// 		return true;
// 	}
//
// 	inline void mark(int x, int y)
// 	{
// 		char ch;
// 		if (box[x][y] == '.')
// 			ch = '#';
// 		else
// 			ch = '.';
// 		box[x][y] = ch;
// 		for (int i = 0; i < 4; ++i)
// 		{
// 			int xx = x + dx[i];
// 			int yy = y + dy[i];
// 			box[xx][yy] = ch;
// 		}
// 	}
// private:
// 	int ans;
// };
// int main(int argc, char const *argv[])
// {
// 	int T;
// 	cin >> T;
// 	while (T--)
// 	{
// 		cin >> row >> col;
// 		for (int i = 0; i < row; ++i)
// 		{
// 			cin >> box[i];
// 		}
// 		Solution solution;
// 		int res = solution.play_block();
// 		cout<<res<<endl;
// 	}
// 	return 0;
// }




/* - error code - */
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN=100,MAXM=100;

// char mat[MAXN][MAXM];

// bool check(int row,int col,int x,int y)
// {
// 	if(!((x+2<row) && (y-1>=0) && (y+1<col)))
// 		return false;
// 	if(!(mat[x+1][y]=='.' && mat[x+2][y]=='.' && mat[x][y-1]=='.' && mat[x][y]=='.' && mat[x][y+1]=='.'))
// 		return false;
// 	return true;
// }
// int main(int argc, char const *argv[])
// {
// 	int T;
// 	cin>>T;
// 	while(T--)
// 	{
// 		int row,col;
// 		cin>>row,col;
// 		for(int i=0;i<row;++i)
// 			cin>>mat[i];
// 		int ans=0;
// 		for(int i=0;i<row;++i)
// 		{
// 			for(int j=0;j<col;++j)
// 			{
// 				if(mat[i][j]=='.')
// 				{
// 					if(check(row,col,i,j))
// 						++ans;
// 				}
// 			}
// 		}
// 		cout<<ans<<endl;
// 	}
// 	return 0;
// }