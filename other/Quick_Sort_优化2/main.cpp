/**
 * -----------------------------------------------------------------
 * Copyright (c) 2013 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

class Solution
{
public:
    void QuickSort(vector<int>& ve) // 第一层函数：外包函数
    {
        QSort(ve,0,ve.size()-1);
    }

    void QSort(vector<int>& ve,int low,int high) //第二层函数：递归函数（实现分割数组的作用）
    {
        if(low<high)
        {
            int pos=partition(ve,low,high);
            QSort(ve,low,pos-1);
            QSort(ve,pos+1,high);
        }
    }

    int partition(vector<int>& ve,int low,int high)  // 第三层函数：有序函数（交换数据，使ve[low~high]有序，并返回中间位置）
    {
        //******
        // 优化2:直接改变ve[low]的中间运行值，减少交换次数：
        int mid=(low+high)>>1;
        if(ve[high]<ve[low])
            swap(ve[high],ve[low]);
        if(ve[high]<ve[mid])
            swap(ve[high],ve[mid]);
        if(ve[low]<ve[mid])
            swap(ve[low],ve[mid]);

        int val=ve[low];
        while(low<high)
        {
            while(low<high && ve[high]>=val)
                --high;
            ve[low]=ve[high];
            swap(ve[low],ve[high]);
            while(low<high && ve[low]<=val)
                ++low;
            ve[high]=ve[low];
        }
        //*** 还原
        ve[low]=val;
        return low;
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> ve(n);
        for(int i=0;i<n;++i)
            cin>>ve[i];
        Solution solution;
        solution.QuickSort(ve);
        for(auto ptr:ve)
            cout<<ptr<<" ";
        cout<<endl;
    }
    return 0;
}
/*

*/
