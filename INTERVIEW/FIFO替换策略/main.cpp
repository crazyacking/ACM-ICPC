#include <bits/stdc++.h>
using namespace std;


// FIFO 先进先出原则
class Solution
{
public:
    Solution(int si)
    {
        _size=si;
        top_idx=0; // 队列top的下标
        cache.clear();
        exist.clear();
    }
    int check_page(int k)
    {
        if(exist.count(k)>=1) //hit the target
            return k;

        // not exist on cache
        if(cache.size()<_size)
        {
            cache.push_back(k);
            exist.insert(k);
        }
        else // replace
        {
            exist.erase(cache[top_idx]);
            exist.insert(k);
            cache[top_idx]=k;
            ++top_idx;
            top_idx%=_size;
        }
        return -1;
    }

private:
    int _size,top_idx;
    vector<int> cache;// 模拟队列
    set<int> exist;
};

/**<
改进：
1.如果页面驻留集（cache）的大小很小的话，没必要使用set来判断是否存在于驻留集中，直接扫一遍来查找，节约了空间
 */

int main()
{
    freopen("H:\\Code_Fantasy\\in.txt","r",stdin);
    int n,page_number;
    while(cin>>n)
    {
        int miss=0;
        Solution solution(3); // set the cache size
        for(int i=0;i<n;++i)
        {
            cin>>page_number;
            if(solution.check_page(page_number)==-1)
                ++miss;
        }
        cout<<"Total missing page: "<<miss<<endl;
        cout<<"The shooting rate is: "<<1.0-(1.*miss/n)<<endl;
        cout<<"=====================================End."<<endl;
    }
    return 0;
}
/*

12
1 2 3 4 1 2 5 1 2 3 4 5

17
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1

*/
