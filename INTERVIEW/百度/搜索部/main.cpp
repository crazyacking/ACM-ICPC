//����һ���ַ������硰abcdef����Ҫ��д��������̡�defabc����λ���ǿɱ��

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string changeString(string s,int n)
    {
        if(n>=s.length())
            return s;
        return s.substr(s.length()-n,s.length()-1)+s.substr(0,s.length()-n);
    }
};

int main()
{
    int n;
    string s;
    while(cin>>s>>n)
    {
        Solution solution;
        string ans=solution.changeString(s,n);
        cout<<ans<<endl;
    }
    return 0;
}
