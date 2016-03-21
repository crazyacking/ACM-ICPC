/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-14-19.02
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

class Solution
{
public:
    int work_func(string expression)
    {
        stack<int> stack_int;
        for(int i=0; i<expression.length(); ++i)
        {
            if(expression[i]>='0' && expression[i]<='9')
                stack_int.push(expression[i]-'0');
            else
            {
                int a=stack_int.top();
                stack_int.pop();
                int b=stack_int.top();
                stack_int.pop();
                cout<<a<<" "<<b<<endl;
                int calculated_value=0;
                char ch=expression[i];
                if(ch=='+')
                    calculated_value=a+b;
                else if(ch=='-')
                    calculated_value=a-b;
                else if(ch=='*')
                    calculated_value=a*b;
                else if(ch=='/')
                {
                    if(!b)
                    {
                        puts("Error:divide by zero.");
                        break;
                    }
                    calculated_value=a/b;
                }
                stack_int.push(calculated_value);
            }
        }
        return stack_int.top();
    }
};

int main()
{
    string expression("23*45-*");
    Solution solution;
    int ans=solution.work_func(expression);
    cout<<ans<<endl;
    return 0;
}
/*

*/
