#include <bits/stdc++.h>
using namespace std;

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

class Solution
{
public:
    bool canArrangeWords(int num,char** arr)
    {
        // WRITE YOUR CODE HERE
        char** t_arr=arr;
        vector<pair<char,char> > words;
        for(int i=0; i<num; ++i)
        {
            char *now_str=(*(t_arr));
            char first_ch=now_str[0],last_ch;
            for(; (*now_str)!='\0'; ++now_str)
                last_ch=(*now_str);
            words.push_back(make_pair(first_ch,last_ch));
            ++t_arr;
        }
        int who[num];
        for(int i=0; i<num; ++i) who[i]=i;
        for(int i=0; i<num; ++i)
        {
            for(int j=0; j<num; ++j)
            {
                if((i!=j)&&
                        (words[i].second!='@')&&
                        (words[j].first!='@')&&
                        (who[i]!=j && who[j]!=i)&&
                        (words[i].second==words[j].first))
                {
                    words[i].second='@';
                    words[j].first='@';
                    who[i]=j,who[j]=i;
                    break;
                }
            }
        }
        int cnt_first=0,cnt_last=0;
        for(int i=0; i<num; ++i)
        {
            if(words[i].first!='@')
                ++cnt_first;
            if(words[i].second!='@')
                ++cnt_last;
        }
        if(cnt_first<=1 && cnt_last<=1)
            return true;
        return false;
    }
};
// FUNCTION SIGNATURE ENDS

int main()
{
    freopen("G:\\nowcoder\\1.in","r",stdin);
    freopen("G:\\nowcoder\\1.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	char *arr[n];
    	char t_str[200];
    	for(int i=0;i<n;++i)
    	{
    	    cin>>t_str;
    	    int len=strlen(t_str);
    		arr[i]=new char(len+1);
    		strncpy(arr[i],t_str,len+1);
    	}
    	Solution solution;
    	if(solution.canArrangeWords(n,arr))
    		cout<<"Yes"<<endl;
    	else
    		cout<<"No"<<endl;
    }
    return 0;
}
/*

1
3
abc
cdefg
gljl
----------------------
Yes
*/
