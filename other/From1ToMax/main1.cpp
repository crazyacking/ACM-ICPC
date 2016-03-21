#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Print1ToMax(int n)
    {
        if(n<=0)
            return ;
        char str[n+1];
        memset(str,'0',sizeof str);
        for(int i=0;i<=9;++i)
        {
            str[0]='0'+i;
            Print1ToMaxDigitRecursively(str,n+1,1);
        }
    }


    void print(char* str,int len)
    {
        int i=-1;
        while(str[++i]=='0');
        for(;i<len-1;++i)
            printf("%c",str[i]);
        puts("");
    }
    void Print1ToMaxDigitRecursively(char* str,int len,int idx)
    {
        if(idx==len-1)
        {
            print(str,len);
            return;
        }
        for(int i=0;i<=9;++i)
        {
             str[idx]=i+'0';
             Print1ToMaxDigitRecursively(str,len,idx+1);
        }
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
         Solution solution;
         solution.Print1ToMax(n);
    }
    return 0;
}
