#include <bits/stdc++.h>
using namespace std;

bool check(int n,vector<string> & strs)
{
    int si=strs.size();
    string sub=strs[0].substr(strs[0].length()-n,n);
    for(int i=1;i<si;++i)
    {
        string ssub=strs[i].substr(strs[i].length()-n,n);
        if(sub!=ssub)
            return false;
    }
    return true;
}

int main()
{
    int n;
    while(cin>>n)
    {
        getchar();
        vector<string> strs(n);
        string str;
        char s1[3000];
        int min_len=0x3f3f3f3f;
        for(int i=0;i<n;++i)
        {
            gets(s1);
            str=string(s1);
            strs[i]=str;
            min_len=min(min_len,(int)str.length());
        }
        int low=0,high=min_len;
        while(low<high)
        {
            int mid=(low+high);
            if(check(mid,strs))
                low=mid;
            else high=mid-1;
        }
        if(!low)
            cout<<"nai"<<endl;
        else
            cout<<strs[0].substr(strs[0].length()-low,low)<<endl;
    }
}
