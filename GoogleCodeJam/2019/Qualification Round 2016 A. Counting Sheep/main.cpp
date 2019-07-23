#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int n)
    {
        string str;
        change_int_to_str(n,str);
        string sstr(str);
        bool f[10]={false};
        int k=1,len,cnt=0;
        while(1)
        {
            mul(k++,str);
            len=str.length();
            for(int i=0;i<len;++i)
            {
                if(!f[str[i]-'0'])
                {
                    f[str[i]-'0']=true;
                    cnt++;
                }
                if(cnt>=10)
                    break;
            }
            if(cnt>=10)
                break;
            str=sstr;
        }
        reverse(str.begin(),str.end());
        return str;
    }

    void mul(int k,string &str)
    {
        int carry=0,len=str.length();
        int now;
        for(int i=0;i<len;++i)
        {
            now=k*(str[i]-'0')+carry;
            str[i]=now%10+'0';
            carry=now/10;
        }
        while(carry)
        {
            str+=(carry%10+'0');
            carry/=10;
        }
    }

    void change_int_to_str(int x,string &str)
    {
        char ch;
        while(x)
        {
            ch=x%10+'0';
            str+=ch;
            x/=10;
        }
    }
};

int main()
{
    freopen("C:\\Users\\crazyacking\\Downloads\\A-large.in","r",stdin);
    freopen("C:\\Users\\crazyacking\\Downloads\\out.txt","w",stdout);

    int T;
    cin>>T;
    for(int Cas=1;Cas<=T;++Cas)
    {
        int n;
        cin>>n;
        if(!n)
        {
            cout<<"Case #"<<Cas<<": INSOMNIA"<<endl;
            continue;
        }
        Solution solution;
        string ans=solution.solve(n);
        cout<<"Case #"<<Cas<<": "<<ans<<endl;
    }
    return 0;
}
