#include <bits/stdc++.h>
using namespace std;

bool fib[110];

void init_fib()
{
    fill(fib,fib+110,false);
    int a=1,b=1,c=2;
    fib[a]=fib[b]=fib[c]=true;
    while(c<=100)
    {
        c=a+b;
        a=b;
        b=c;
        if(c<110)
            fib[c]=true;
    }
}

int main()
{
//    freopen("G:\\nowcoder\\1.out","w",stdout);
    init_fib();
    string s;
    while(cin>>s)
    {
        set<string> ans;
        int len=s.length();
        unordered_set<char> se;
        for(int i=0;i<len;++i)
        {
            for(int j=i;j<len;++j)
            {
                se.clear();
                for(int k=i;k<=j;++k)
                    se.insert(s[k]);
                if(fib[se.size()])
                    ans.insert(s.substr(i,j-i+1));
            }
        }
        for(auto p:ans)
        {
            if(str.compare(p)==0)
            {
                puts("===============================Program Run Here !=============================");

            }

//            cout<<p<<endl;
        }
    }
    return 0;
}
