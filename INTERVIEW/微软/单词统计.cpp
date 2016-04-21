#include <bits/stdc++.h>
using namespace std;
/**< 第一次白板上写代码，手动对齐TAT，坑出翔 */
class Solution
{
public:
    map<string,int> cnt_words(vector<string> &strs)
    {
        map<string,int> res;
        int n=strs.size();
        for(int i=0; i<n; ++i)
            res[strs[i]]++;
        return res;
    }
};

bool is_num(string &str)
{
    int len=str.length();
    for(int i=len-1; i>=0; --i)
        if(!(str[i]>='0' && str[i]<='9'))
            return false;
    return true;
}

int get_num(string str)
{
    int len=str.length(),num=0;
    for(int i=len-1; i>=0; --i)
    {
        num*=10;
        num+=str[i]-'0';
    }
    return num;
}

int main()
{
    int n;
    string num;
    while(cin>>num)
    {
        if(!is_num(num))
        {
            cout<<"invalid input(please input a number)."<<endl;
            continue;
        }
        n=get_num(num);
        if(!(n>0 && n<=50000))
        {
            cout<<"please input a number between 1 from 50000!"<<endl;
            continue;
        }
        Solution solution;
        vector<string> strs(n);
        for(int i=0; i<n; ++i)
            cin>>strs[i];
        map<string,int> res=solution.cnt_words(strs);
        map<string,int>::iterator iter;
        for(iter=res.begin(); iter!=res.end(); ++iter)
        {
            cout<<(*iter).first<<" "<<(*iter).second<<endl;
        }
        cout<<endl;
    }
}


/*

5
hello
world
ok
hello
ok
----------------------------------
0
----------------------------------
10
ab
abc
ba
bac
fdsfedv
fasdfewjjflaifewjflasfsdlajeiowfjlaffewioajfajd
cjvlajiflasjfejfa
fdsfdsafefds
ab
abc
----------------------------------
-1
----------------------------------

*/
