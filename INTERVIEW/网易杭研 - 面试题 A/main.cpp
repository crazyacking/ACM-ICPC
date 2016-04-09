/**<
Mean:
    ��һ�������Ϊ(n,m,h)�ĳ�����,�ڲ���ÿһ��С����������һ�����֡����ȡ�˵�ǰ���С�����壬С������ģ�
        1.�����������㽫����ʧ;
        2.�����������н�����ʧ;
        3.ǰ����������������ʧ;
    �ҳ�һ��ȡ����ʹ��ȡ��������sum���
 */


/**<
Analyse:
    ����������ά�����:һ�ֽ��������dp+״̬ѹ��������ÿһ�У�ö�����п��ܵ��������������������Ϊ1���֦������һ��map����״̬��ֵ��ӳ�䣻�ڶ�����ݵ�һ������������map��Ȼ���������map����key���������������벻Ϊ0�����֦��һֱdp�����һ�о���answer��
    ʱ�临�Ӷȣ�(2^n)*log(n)*n
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
