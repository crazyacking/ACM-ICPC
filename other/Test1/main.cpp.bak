/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-20-20.59
* Time: 0MS
* Memory: 137KB
*/
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define  LL long long
#define  ULL unsigned long long
using namespace std;

int __crazyacking_now___,__kitExpression_Tree__(string),__Terminal__now___(string),___Factor_Or__now__(string),__Kat_number_(string);
int __dx__number_(string),__dbd__number__(string),__and__number__(string) ,__Number_Xor_(string),Or(string),__and__number__2(string),___Orz__number___(string);
string string__;

/**< set back the __crazyacking_now___'s number */
int __Kat_number_(string s)
{
      int res = 0;
      while('0' <= s[__crazyacking_now___] && s[__crazyacking_now___] <= '9')
      {
            res = res * 10 + s[__crazyacking_now___] - '0';
            __crazyacking_now___++;
      }
      return res;
}


/**< calculate Or */
int Or(string s)
{
      int res = __Number_Xor_(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '|' && s[__crazyacking_now___ + 1] != '|')
            {
                  ++__crazyacking_now___;
                  res = (res | __Number_Xor_(s));
            }
            else
            {
                  break;
            }
      }
      return res;
}

/**< Detect the base */
int __dbd__number__(string s)
{
      int res = __dx__number_(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '=' && s[__crazyacking_now___ + 1] == '=')
            {
                  __crazyacking_now___ += 2;
                  res = (res == __dx__number_(s));
            }
            else if(s[__crazyacking_now___] == '!' && s[__crazyacking_now___ + 1] == '=')
            {
                  __crazyacking_now___ += 2;
                  res = (res != __dx__number_(s));
            }
            else
            {
                  break;
            }
      }
      return res;
}


int __Number_Xor_(string s)
{
      int res = __and__number__(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '^')
            {
                  ++__crazyacking_now___;
                  res = (res ^ __and__number__(s));
            }
            else
            {
                  break;
            }
      }
      return res;
}

/**< judge __and__number__2 ,Is have other case? */
int __and__number__2(string s)
{
      int res = Or(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '&' && s[__crazyacking_now___ + 1] == '&')
            {
                  __crazyacking_now___ += 2;
                  res = (res && Or(s));
            }
            else
            {
                  break;
            }
      }
      return res;
}
int __and__number__(string s)
{
      int res = __dbd__number__(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '&' && s[__crazyacking_now___ + 1] != '&')
            {
                  ++__crazyacking_now___;
                  res = (res & __dbd__number__(s));
            }
            else
            {
                  break;
            }
      }
      return res;
}


int __dx__number_(string s)
{
      int res = __kitExpression_Tree__(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '>' && s[__crazyacking_now___ + 1] == '=')
            {
                  __crazyacking_now___ += 2;
                  res = (res >= __kitExpression_Tree__(s));
            }
            else if(s[__crazyacking_now___] == '<' && s[__crazyacking_now___ + 1] == '=')
            {
                  __crazyacking_now___ += 2;
                  res = (res <= __kitExpression_Tree__(s));
            }
            else if(s[__crazyacking_now___] == '>')
            {
                  ++__crazyacking_now___;
                  res = (res > __kitExpression_Tree__(s));
            }
            else if(s[__crazyacking_now___] == '<')
            {
                  ++__crazyacking_now___;
                  res = (res < __kitExpression_Tree__(s));
            }
            else
            {
                  break;
            }
      }
      return res;
}
/**< Factor or  */
int ___Factor_Or__now__(string s)
{
      int res = __Kat_number_(s);
      if(s[__crazyacking_now___] == '(')
      {
            __crazyacking_now___++;
            res += ___Orz__number___(s);
            __crazyacking_now___++;
      }
      return res;
}

int __kitExpression_Tree__(string s)
{
      int res = __Terminal__now___(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '+')
            {
                  __crazyacking_now___++;
                  res += __Terminal__now___(s);
            }
            else if(s[__crazyacking_now___] == '-')
            {
                  __crazyacking_now___++;
                  res -= __Terminal__now___(s);
            }
            else
            {
                  break;
            }
      }
      return res;
}

int __Terminal__now___(string s)
{
      int res = ___Factor_Or__now__(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '*')
            {
                  __crazyacking_now___++;
                  res *= ___Factor_Or__now__(s);
            }
            else if(s[__crazyacking_now___] == '&')/**<  */
            {
                  __crazyacking_now___++;
                  res /= ___Factor_Or__now__(s);
            }
            else if(s[__crazyacking_now___] == '%')
            {
                  __crazyacking_now___++;
                  res = res % ___Factor_Or__now__(s);
            }
            else
            {
                  break;
            }
      }
      return res;
}



/**< count the __and__number__2 */
int ___Orz__number___(string s)
{
      int res = __and__number__2(s);
      for(;;)
      {
            if(s[__crazyacking_now___] == '|' && s[__crazyacking_now___ + 1] == '|')
            {
                  __crazyacking_now___ += 2;/**<  */
                  res = (res || __and__number__2(s));
            }
            else
            {
                  break;
            }
      }
      return res;
}

int main()
{
      while(cin >> string__)
      {
            if(string__[0] == '0' && string__.size() == 1)
            {
                  return 0;
            }
            __crazyacking_now___ = 0;
            cout << ___Orz__number___(string__) << endl;
      }
}
