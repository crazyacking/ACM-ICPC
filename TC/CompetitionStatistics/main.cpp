#include <bits/stdc++.h>
using namespace std;

class CompetitionStatistics{
public:
    int consecutiveGrowth(vector<int> r){
        int m,max;
        max=-1;m=0;
        for(int i=0;i<r.size();i++)
          if(r[i]>0)m++;
          else {if(max<m)max=m;m=0;}
          if(m>max)max=m;
         return max;

    }
};

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
        CompetitionStatistics cs;
        int ans=cs.consecutiveGrowth(nums);
        cout<<ans<<endl;

    }
    return 0;
}
/*

*/
