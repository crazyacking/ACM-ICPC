#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void work(int n)
    {
        char str[n+1];
        memset(str,'0',sizeof str);
        while(add(str,n+1))
        {
            print(str,n+1);
        }
    }

    void print(char *str,int len)
    {
        bool flag=0;
        int i=-1;
        while(str[++i]=='0');
        for(;i<len;++i)
        {
            printf("%c",str[i]);
        }
        puts("");
    }
    bool add(char* str,int len)
    {
        str[len-1]+=1;
        int carry=0,temp;
        for(int i=len-1;i>=0;--i)
        {
            str[i]+=carry;
            temp=str[i]-'0';
            carry=temp/10;
            str[i]=(temp%10)+'0';
        }
        if(str[0]-'0'>0)
            return false;
        return true;
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
         Solution solution;
         solution.work(n);
    }
    return 0;
}
