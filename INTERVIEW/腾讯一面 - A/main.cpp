//把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，不能申请额外的空间

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toBack(string& s)
    {
        int n=s.length(),i=0;
        while(i<n)
        {
            int j=i;
            for(; j<n; ++j)
            {
                if(s[j]>='a' && s[j]<='z')
                    break;
            }
            if(j<n)
            {
                for(int k=j; k-1>=0; --k)
                {
                    if(s[k-1]>='A' && s[k-1]<='Z')
                        swap(s[k],s[k-1]);
                    else break;
                }
            }
            ++i;
        }
        return s;
    }
};

int main()
{
    string s;
    while(cin>>s)
    {
        Solution solution;
        solution.toBack(s);
        cout<<s<<endl;
    }
    return 0;
}
