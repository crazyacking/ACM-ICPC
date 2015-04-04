#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef long long LL;


const int maxI = 1e8;
const int Len = 8;

struct BigInt {

    vi num;
    bool symbol;

    BigInt() { num.clear(); symbol = 0; }
    BigInt(int x) { symbol = 0; if (x < 0) { symbol = 1; x = -x; } num.push_back(x % maxI); if (x >= maxI) num.push_back(x / maxI); }
    BigInt(bool s, vi x) { symbol = s;  num = x; }
    BigInt(char s[]) {
        int len = strlen(s), x = 1, sum = 0, p = s[0] == '-';
        symbol = p;
        for (int i = len - 1; i >= p; i--) {
            sum += (s[i] - '0') * x;
            x *= 10;
            if (x == 1e8 || i == p) {
                num.push_back(sum);
                sum = 0;
                x = 1;
            }
        }
        while (num.back() == 0 && num.size() > 1) num.pop_back();
    }

    void push(int x) { num.push_back(x); }

    BigInt abs() const { return BigInt(false, num); }

    bool smaller(const vi &a, const vi &b) const {
        if (a.size() != b.size()) return a.size() < b.size();
        for (int i = a.size() - 1; i >= 0; i--) {
            if (a[i] != b[i]) return a[i] < b[i];
        }
        return 0;
    }

    bool operator < (const BigInt &p) const {
        if (symbol && !p.symbol) return true;
        if (!symbol && p.symbol) return false;
        if (symbol && p.symbol) return smaller(p.num, num);
        return smaller(num, p.num);
    }

    bool operator > (const BigInt &p) const {
        return p < *this;
    }

    bool operator == (const BigInt &p) const {
        return !(p < *this) && !(*this < p);
    }

    bool operator >= (const BigInt &p) const {
        return !(*this < p);
    }

    bool operator <= (const BigInt &p) const {
        return !(p < *this);
    }

    vi add(const vi &a, const vi &b) const {
        vi c;
        c.clear();
        int x = 0;
        for (int i = 0; i < a.size(); i++) {
            x += a[i];
            if (i < b.size()) x += b[i];
            c.push_back(x % maxI);
            x /= maxI;
        }
        for (int i = a.size(); i < b.size(); i++) {
            x += b[i];
            c.push_back(x % maxI);
            x /= maxI;
        }
        if (x) c.push_back(x);
        while (c.back() == 0 && c.size() > 1) c.pop_back();
        return c;
    }

    vi sub(const vi &a, const vi &b) const {
        vi c;
        c.clear();
        int x = 1;
        for (int i = 0; i < b.size(); i++) {
            x += maxI + a[i] - b[i] - 1;
            c.push_back(x % maxI);
            x /= maxI;
        }
        for (int i = b.size(); i < a.size(); i++) {
            x += maxI + a[i] - 1;
            c.push_back(x % maxI);
            x /= maxI;
        }
        while (c.back() == 0 && c.size() > 1) c.pop_back();
        return c;
    }

    vi mul(const vi &a, const vi &b) const {
        vi c;
        c.resize(a.size() + b.size());
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                LL tmp = (LL)a[i] * b[j] + c[i + j];
                c[i + j + 1] += tmp / maxI;
                c[i + j] = tmp % maxI;
            }
        }
        while (c.back() == 0 && c.size() > 1) c.pop_back();
        return c;
    }

    vi div(const vi &a, const vi &b) const {
        vi c(a.size()), x(1, 0), y(1, 0), z(1, 0), t(1, 0);
        y.push_back(1);
        for (int i = a.size() - 1; i >= 0; i--) {
            z[0] = a[i];
            x = add(mul(x, y), z);
            if (smaller(x, b)) continue;
            int l = 1, r = maxI - 1;
            while (l < r) {
                int m = (l + r + 1) >> 1;
                t[0] = m;
                if (smaller(x, mul(b, t))) r = m - 1;
                else l = m;
            }
            c[i] = l;
            t[0] = l;
            x = sub(x, mul(b, t));
        }
        while (c.back() == 0 && c.size() > 1) c.pop_back();
        return c;
    }

    BigInt operator + (const BigInt &p) const{
        if (!symbol && !p.symbol) return BigInt(false, add(num, p.num));
        if (!symbol && p.symbol) return *this >= p.abs()? BigInt(false, sub(num, p.num)) : BigInt(true, sub(p.num, num));
        if (symbol && !p.symbol) return (*this).abs() > p? BigInt(true, sub(num, p.num)) : BigInt(false, sub(p.num, num));
        return BigInt(true, add(num, p.num));
    }

    BigInt operator - (const BigInt &p) const {
        return *this + BigInt(!p.symbol, p.num);
    }

    BigInt operator * (const BigInt &p) const {
        BigInt res(symbol ^ p.symbol, mul(num, p.num));
        if (res.symbol && res.num.size() == 1 && res.num[0] == 0) res.symbol = false;
        return res;
    }

    BigInt operator / (const BigInt &p) const {
        if (p == BigInt(0)) return p;
        BigInt res(symbol ^ p.symbol, div(num, p.num));
        if (res.symbol && res.num.size() == 1 && res.num[0] == 0) res.symbol = false;
        return res;
    }

    BigInt operator % (const BigInt &p) const {
        return *this - *this / p * p;
    }

    void show() const {
        if (symbol) putchar('-');
        printf("%d", num[num.size() - 1]);
        for (int i = num.size() - 2; i >= 0; i--) {
            printf("%08d", num[i]);
        }
        putchar('\n');
    }

    int TotalDigit() const {
        int x = num[num.size() - 1] / 10, t = 1;
        while (x) {
            x /= 10;
            t++;
        }
        return t + (num.size() - 1) * Len;
    }

};