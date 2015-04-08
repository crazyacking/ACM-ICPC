#include <iostream>
#include <sstream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector <long long> v;
    v.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &v[i]);
    sort(v.rbegin(), v.rend());
    int i = 0;
    long long result = 0;
    long long store = -1LL;
    while (true)
    {
        if (i >= n - 1)
            break;
        else
            if (v[i] == v[i + 1] || v[i] == v[i + 1] + 1)
            if (store == -1)
                store = v[i + 1], i = i += 2;
            else
                result += v[i + 1] * store, i += 2, store = -1LL;
                else
                    i++;
    }
    cout << result;
    return 0;
}
