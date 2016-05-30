#include <bits/stdc++.h>
using namespace std;
class NumericalSequence
{
public:
    int makePalindrome(vector <int>);
};
int NumericalSequence::makePalindrome(vector <int> sequence)
{
    int len, be, en, tot;
    len = sequence.size();
    be = 0;
    en = len - 1;
    tot = 0;
    while (be < en)
    {
        if (sequence[be] == sequence[en])
        {
            be ++;
            en --;
            continue;
        }
        if (sequence[be] < sequence[en])
        {
            sequence[be+1] += sequence[be];
            tot++;
            be++;
            continue;
        }
        if (sequence[be] > sequence[en])
        {
            sequence[en-1] += sequence[en];
            tot++;
            en--;
            continue;
        }
    }
    return tot;
}

int main()
{
//    freopen("G:\\nowcoder\\1.in","r",stdin);
//    freopen("G:\\nowcoder\\1.out","w",stdout);
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
        {
            cin>>nums[i];
        }
        NumericalSequence ns;
        int ans=ns.makePalindrome(nums);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
