//��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�����������Ŀռ�

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
