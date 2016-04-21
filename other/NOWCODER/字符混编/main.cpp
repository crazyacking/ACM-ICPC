#include "bits/stdc++.h"
using namespace std;

class Mixture {
public:
	bool chkMixture(string A, int n, string B, int m, string C, int v) {
		if (v != n + m)
			return false;
		bool dp[n + 1][m + 1];
		memset(dp,0,sizeof dp);
		for (int i = 1; i < n; ++i)
			dp[i][0] = (A[i-1] == C[i-1] ? 1 : 0);
		for (int i = 1; i < m; ++i)
			dp[0][i] = (B[i-1] == C[i-1] ? 1 : 0);
		for (int i = 1; i <=n; ++i) {
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = (A[i-1] == C[i + j - 1] && dp[i - 1][j]) || (B[j-1] == C[i + j - 1] && dp[i][j - 1]);
			}
		}
		cout<<"------------------------------------------------------------"<<endl;
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"------------------------------------------------------------"<<endl;
		return dp[n][m];
	}
};

int main(int argc, char const *argv[]) {
	string s1, s2, s3;
	while (cin >> s1 >> s2 >> s3) {
		Mixture solution;
		if (solution.chkMixture(s1, s1.length(), s2, s2.length(), s3, s3.length()))
			cout << "Yes." << endl;
		else
			cout << "No." << endl;
	}
	return 0;
}