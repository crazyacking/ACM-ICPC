#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

#ifdef __GNUC__
#define int64 long long
#else /* MSVC, say */
#define int64 __int64
#endif

class VariableSolve {
public:
  string srt(string s) {
    for (int i=0; i+1 < s.size(); i++)
      for (int j=0; j+1 < s.size(); j++)
        if (s[j] > s[j+1]) {
          char tmp = s[j];
          s[j] = s[j+1];
          s[j+1] = tmp;
        }
    return s;
  }

  char negs(char c) {
    if (c=='+')
      return '-';
    else
      return '+';
  }

    vector <string> getSolutions(string equation) {
    equation += '+';
        vector<string> therm;
    vector<char> sign;
    bool was_eqs = false;
    char last_char = '+';
    string cur_therm = "";
    int i,j;
    for (i=0; i < equation.size(); i++) {
      if ((equation[i]=='+')||(equation[i]=='-')||(equation[i]=='=')) {
        therm.push_back(srt(cur_therm));
        if (was_eqs)
          sign.push_back(negs(last_char));
        else
          sign.push_back(last_char);
        if (equation[i] == '=') {
          was_eqs = true;
          last_char = '+';
        } else last_char = equation[i];
        cur_therm = "";
      } else cur_therm += equation[i];
    }
    vector<string> ret;
    for (char let='A'; let<='Z'; let++) {
      vector<string> newtherm;
      vector<int> a;
      vector<int> b;
      vector<int> c;
      for (i=0; i < therm.size(); i++) {
        int cnt_meet = 0;
        string therm_after = "";
        for (j=0; j < therm[i].size(); j++)
          if (therm[i][j] == let)
            cnt_meet++;
          else
            therm_after += therm[i][j];
        int x=0;
        while ((x < newtherm.size()) && (newtherm[x] != therm_after)) x++;
        if (x == newtherm.size()) {
          newtherm.push_back(therm_after);
          a.push_back(0);
          b.push_back(0);
          c.push_back(0);
        }
        if (cnt_meet == 0) {
          if (sign[i] == '+')
            c[x]++;
          else
            c[x]--;
        }
        if (cnt_meet == 1) {
          if (sign[i] == '+')
            b[x]++;
          else
            b[x]--;
        }
        if (cnt_meet == 2) {
          if (sign[i] == '+')
            a[x]++;
          else
            a[x]--;
        }
      }
      vector<double> root;
      vector<bool> isgood;
      for (i=0; i < newtherm.size(); i++) {
        if (root.size() != 0) {
          for (j=0; j < root.size(); j++) {
            if (fabs(a[i] * root[j] * root[j] + b[i] * root[j] + c[i]) > 1e-10)
              isgood[j] = false;
          }
        } else {
          if ((a[i] == 0) && (b[i] == 0)) {
            if (c[i] != 0) break;
          } else
          if (a[i] == 0) {
            root.push_back(-c[i] / (double)b[i]);
            isgood.push_back(true);
          } else {
            int d = b[i]*b[i]-4*a[i]*c[i];
            if (d < 0) break;
            if (d == 0) {
              root.push_back(- b[i] / 2.0 / (double)a[i]);
              isgood.push_back(true);
            }
            if (d > 0) {
              root.push_back((- b[i] - sqrt((double)d)) / 2.0 / (double)a[i]);
              root.push_back((- b[i] + sqrt((double)d)) / 2.0 / (double)a[i]);
              isgood.push_back(true);
              isgood.push_back(true);
            }
          }
        }
      }
      for (i=0; i < root.size(); i++)
        if (isgood[i]) {
          string s = "";
          s += let;
          ret.push_back(s);
        }
    }
    return ret;
    }

};
