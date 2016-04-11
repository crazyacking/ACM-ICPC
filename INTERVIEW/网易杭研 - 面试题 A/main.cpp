/**<
Mean:
    ��һ�������Ϊ(n,m,h)�ĳ�����,�ڲ���ÿһ��С����������һ�����֡����ȡ�˵�ǰ���С�����壬С������ģ�
        1.�����������㽫����ʧ;
        2.�����������н�����ʧ;
        3.ǰ����������������ʧ;
    �ҳ�һ��ȡ����ʹ��ȡ��������sum������sum��
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMax(vector<vector<vector<int> > > &cube)
    {
        int n=cube.size();
        vector<vector<int> > dp2(n,vector<int>(n,0));
        vector<int> tp(n);
        // 3D zip to 2D
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    tp[k]=cube[i][k][j];// be careful
                }
                dp2[i][j]=zipToPoint(tp);
            }
        }
        // print 2D
//        puts("-------------------------------");
//        for(int i=0;i<n;++i)
//        {
//            for(int j=0;j<n;++j)
//                cout<<dp2[i][j]<<" ";
//            cout<<endl;
//        }
//        puts("-------------------------------");

        vector<int> dp1(n,0);
        // 2D zip to answer
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                tp[j]=dp2[i][j];
            dp1[i]=zipToPoint(tp);
        }
        return zipToPoint(dp1);
    }

    int zipToPoint(vector<int> & nums)
    {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;++i)
        {
            if(i==1)
                dp[i]=max(dp[0],nums[1]);
            else
                dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};


int main()
{
//    freopen("G:\\nowcoder\\in","r",stdin);
//    freopen("G:\\nowcoder\\out","w",stdout);
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        vector<vector<vector<int> > > cube(n,vector<vector<int> >(n,vector<int>(n,0)));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<n;++k)
                    scanf("%d",&cube[i][j][k]);
            }
        }
        Solution solution;
        int ans=solution.getMax(cube);
        printf("%d\n",ans);
    }
    return 0;
}

/*
-----------------------
1
3
1 2 3
4 5 6
7 8 9

10 11 12
13 14 15
16 17 18

19 20 21
22 23 24
25 26 27
-----------------------
112

*/
