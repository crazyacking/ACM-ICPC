#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int dx[8] = {-1, -1 ,-1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(vector<string> &S, int x, int y, char c) {
    S[x][y] = '#';

    int N = S.size();
    int M = S[0].size();
    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (newX < 0 || newX >= N)
            continue;
        if (newY < 0 || newY >= M)
            continue;
        if (S[newX][newY] == c)
            dfs(S, newX, newY, c);
    }
}

int main() {
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<string> S(N);
        for (int i = 0; i < N; ++i)
            cin >> S[i];

       int king1 = 0, king2 = 0;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (S[i][j] == 'X') {
                    king1++;
                    dfs(S, i, j, S[i][j]);
                } else if (S[i][j] == 'O') {
                    king2++;
                    dfs(S, i, j, S[i][j]);
                }

        if (king1 >= king2)
            cout << "X\n";
        else
            cout << "O\n";
    }
}