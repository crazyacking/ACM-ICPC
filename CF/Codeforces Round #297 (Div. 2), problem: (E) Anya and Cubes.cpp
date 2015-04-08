#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
long long a[maxn], b[maxn], fac[maxn];
map <pair<long long, int>, int> L, R;
map <pair<long long, int>, int> :: iterator it;
int main() {
	int n, k;
	long long S;
	scanf("%d%d%I64d", &n, &k, &S);
	long long upper;
	long long tmp = 1;
	for(upper = 1; (tmp *= (upper + 1)) <= S; upper++);
	int idx = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	fac[0] = 1;
	for(int i = 1; i <= upper; i++) fac[i] = fac[i - 1] * i;
	int u = n / 2;
	int v = n - u;
	for(int i = 0; i < (1 << u); i++) {
		int idx = 0;
		for(int j = 0; j < u; j++) {
			if(i >> j & 1) b[idx++] = a[j];
		}
		for(int r = 0; r < (1 << idx); r++) {
			bool flag = 0;
			for(int p = 0; p < idx; p++) {
				if((r >> p & 1) && b[p] > upper) flag = 1;
			}
			if(flag) continue;
			int cnt = 0;
			long long sum = 0;
			for(int p = 0; p < idx; p++) {
				if(r >> p & 1) {
					cnt++;
					sum += fac[b[p]];
				} else{
					sum += b[p];
				}
			}
			if(sum <= S && cnt <= k) {
				L[make_pair(sum, cnt)]++;
				//printf("LEFT: sum = %I64d, cnt = %d\n", sum, cnt);
			}
		}
	}
	for(int i = 0; i < (1 << v); i++) {
		int idx = 0;
		for(int j = 0; j < v; j++) {
			if(i >> j & 1) b[idx++] = a[u + j];
		}
		for(int r = 0; r < (1 << idx); r++) {
			bool flag = 0;
			for(int p = 0; p < idx; p++) {
				if((r >> p & 1) && b[p] > upper) flag = 1;
			}
			if(flag) continue;
			int cnt = 0;
			long long sum = 0;
			for(int p = 0; p < idx; p++) {
				if(r >> p & 1) {
					cnt++;
					sum += fac[b[p]];
				} else{
					sum += b[p];
				}
			}
			if(sum <= S && cnt <= k) {
				R[make_pair(sum, cnt)]++;
				//printf("LEFT: sum = %I64d, cnt = %d\n", sum, cnt);
			}
		}
	}
	long long ans = 0;
	for(it = L.begin(); it != L.end(); it++) {
		long long u = (it -> first).first;
		int v = (it -> first).second;
		int w = (it -> second);
		//printf("u = %I64d, v = %d, w = %d\n", u, v, w);
		for(int i = 0; i <= k - v; i++) {
			if(R.find(make_pair(S - u, i)) != R.end()) ans += (long long)w * (R[make_pair(S - u, i)]);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}
