#include <bits/stdc++.h>
using namespace std;

int T, n, m;

const int dx[8] = { -1, -1 , -1, 0, 0, 1, 1, 1};
const int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};

void dfs(vector<string> &mp, int x, int y, char c)
{
	mp[x][y] = '#';
	for (int i = 0; i < 8; ++i)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx < n && yy >= 0 && yy < m && mp[xx][yy] == c)
			dfs(mp, xx, yy, c);
	}
}
int main(int argc, char const *argv[])
{
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		vector<string> mp(n);
		for (int i = 0; i < n; ++i)
			cin >> mp[i];
		int k1 = 0, k2 = 0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (mp[i][j] == 'X'){
					++k1;
					dfs(mp,i,j,mp[i][j]);
				}
				else if(mp[i][j]=='O'){
					++k2;
					dfs(mp, i, j, mp[i][j]);
				}
			}
		}
		if (k1 >= k2)
			cout << 'X' << endl;
		else cout << 'O' << endl;
	}
	return 0;
}