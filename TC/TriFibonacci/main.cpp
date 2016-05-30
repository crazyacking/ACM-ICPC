#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

#define all(x) (x).begin(),(x).end()

#define vs vector <string>
#define vi vector <int>
#define vvi vector < vi >
#define p(X) push_back((X))

#define fir(i,j,n) for(int (i)=(j);(i)<(n);(i)++)
class TriFibonacci
{
public:
    int complete(vector <int> A)
    {
        int ret=-1;
        fir(i,0,A.size())
        {
            if (A[i]==-1)
            {
                if (i>=3) A[i]=ret=A[i-1]+A[i-2]+A[i-3];
                else
                {
                    int sum=0;
                    fir(j,0,3) if (A[j]!=-1) sum+=A[j];
                    A[i]=ret=A[3]-sum;
                }
            }
        }
        bool tv=1;
        fir(i,3,A.size())
        {
            if (A[i]!=A[i-1]+A[i-2]+A[i-3]) return -1;
        }
        if (ret<=0) return -1;
        return ret;
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
        TriFibonacci tf;
        int ans=tf.complete(nums);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
