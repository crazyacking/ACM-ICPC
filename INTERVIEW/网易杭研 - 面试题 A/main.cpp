/**<
Mean:
    有一个长宽高为(n,m,h)的长方体,内部的每一个小立方体内有一个数字。如果取了当前这个小立方体，小立方体的：
        1.上下相邻两层将会消失;
        2.左右相邻两列将会消失;
        3.前后相邻两个将会消失;
    找出一种取法，使得取到的数的sum最大。
 */


/**<
Analyse:
    首先来看二维的情况:一种解决方法是dp+状态压缩，对于每一行，枚举所有可能的情况（相邻两个数相与为1则剪枝），用一个map保存状态到值的映射；第二层根据第一层的情况来构造map，然后遍历两个map，对key进行与操作，如果与不为0，则剪枝；一直dp到最后一行就是answer。
    时间复杂度：(2^n)*log(n)*n
 */


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int64_t getMax(vector<vector<int>> mat)
    {
        int64_t res=0;
        int n=mat.size();
        vector<int> zuhe;
        dfs(n,zuhe);
        for(int i=0;i<zuhe.size();++i)
        {
            for(int j=0;j<zuhe.size();++j)
            {
                if(i!=j && !(zuhe[i]&zuhe[j]))
                {

                }
            }
        }

        return res;
    }
    void dfs(int n,vector<int> &zuhe)
    {
        int low=0,high=(1<<n);
        while(low<high)
        {
            if(check(low))
                zuhe.push_back(low);
            ++low;
        }
    }

    void check(int x)
    {
        int b=x&1;
        x>>=1;
        int f=x&1;
        while(x)
        {
            if(f&b)
                return false;
            b=f;
            x>>=1;
            f=x&1;
        }
        return true;
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
                cin>>mat[i][j];
        }
        Solution solution;
        int64_t ans=solution.getMax(mat);
        cout<<ans<<endl;
    }
    return 0;
}
