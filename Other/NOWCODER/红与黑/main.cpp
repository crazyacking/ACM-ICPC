#include <bits/stdc++.h>
using namespace std;

int row, col;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

inline int bfs(vector<string>& mat, int x, int y)
{
	vector<vector<bool> > vis(row,(vector<bool> (col,false)));
	int res = 0;
	queue<pair<int, int> > que;
	while (!que.empty())
		que.pop();
	que.push(make_pair(x, y));
	vis[x][y]=true;
	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();
		int cx = cur.first, cy = cur.second;
		for (int i = 0; i < 4; ++i)
		{
			if ((cx + dx[i] >= 0 && cx + dx[i] < row && cy + dy[i] >= 0 && cy + dy[i] < col)
				&& vis[cx+dx[i]][cy+dy[i]]==false
				&& mat[cx + dx[i]][cy + dy[i]] == '.')
			{
				vis[cx+dx[i]][cy+dy[i]]=true;
				que.push(make_pair(cx + dx[i], cy + dy[i]));
				++res;
			}
		}
	}
	return res+1;
}
int main(int argc, char const *argv[])
{
	while (cin >> row >> col)
	{
		vector<string> mat(row);
		for (int i = 0; i < row; ++i)
			cin >> mat[i];
		int sx, sy;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
				if (mat[i][j] == '@')
					sx = i, sy = j;
		}
		int ans = bfs(mat, sx, sy);
		cout << ans << endl;
	}
	return 0;
}