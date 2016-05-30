#include <bits/stdc++.h>
using namespace std;
class ClapLight
{
public:
    int threshold(vector <int> background)
    {
        int t;
        for (t=0; t<1001; t++)
        {
            int bad = 0;
            bool setsOff = false;
            for (int i=0; i<background.size(); i++)
            {
                if (background[i]>=t)
                    bad++;
                else
                {
                    if (i-1>=0 && background[i-1]>=t && i-2>=0 && background[i-2]>=t && i-3>=0 && background[i-3]<t)
                    {
                        setsOff = true;
                        break;
                    }
                }
            }
            if (bad*2 < background.size() && !setsOff)
                return t;
        }
        return t;
    }
};


int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
        {
            cin>>nums[i];
        }
        ClapLight cl;
        int ans=cl.threshold(nums);
        cout<<ans<<endl;
    }
    return 0;
}
