#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cassert>
using namespace std;
int t[4];
long long mod = 1000000007;

long long pot(int p, int wyk) {
    if(wyk == 0) return 1;
    return (p * pot(p, wyk-1)) % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    for(auto a: s) {
        if(a == 'C') t[0]++;
        if(a == 'T') t[1]++;
        if(a == 'G') t[2]++;
        if(a == 'A') t[3]++;
    }
    int maxi = 0, licz = 0;
    for(int i = 0; i < 4; ++i)
        maxi = max(maxi, t[i]);
    for(int i = 0; i < 4; ++i)
        if(t[i] == maxi) licz++;
    
    cout << pot(licz, n) << "\n";
    return 0;
}
