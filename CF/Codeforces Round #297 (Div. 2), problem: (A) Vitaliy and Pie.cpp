#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>

using namespace std;

#ifndef __GNUC__
    typedef unsigned long int uint;
#endif

typedef signed short int int16;
typedef unsigned short int uint16;
typedef signed long long int int64;
typedef unsigned long long int uint64;
typedef double real;

typedef pair<int, int> pii;
typedef pair<int64, int64> pii64;

const int INF = INT_MAX;
const int64 LINF = LLONG_MAX;
const real EPS = 1e-9;
const int MOD = 1000000007; // 10**9 + 7
const int MAXN = 100001;
const int ALPH = 26; // Latin alphabet size
const int DALPH = 52; // Double Latin alphabet size

#define mp(a, b) make_pair((a), (b))
#define all(a) (a).begin(), (a).end()
#define szof(a) (int)(a).size()

#define pub(a) push_back(a)
#define pob() pop_back()
#define puf(a) push_front(a)
#define pof() pop_front()

#ifdef DEBUG
  #define _show(var) cerr << #var << " = " << var << endl
#else
  #define _show(var) (void)42
#endif

void read(string &s) {
  static char buffer[1 << 18];
  scanf("%s", buffer);
  s = buffer;
}

string s;
int cnt[ALPH];

int main() {
  scanf("%*d");
  
  read(s);
  int ans = 0;
  for (int i = 0; i < szof(s); ++i) {
    if ('a' <= s[i] && s[i] <= 'z') {
      cnt[s[i] - 'a']++;
      continue;
    }
    
    int ind = s[i] - 'A';
    if (cnt[ind] == 0) {
      ++ans;
      continue;
    }
    
    --cnt[ind];
  }
  
  printf("%d\n", ans);
}
