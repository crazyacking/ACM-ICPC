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
    void QuickSort(vector<int>& ve) // ��һ�㺯�����������
    {
        QSort(ve,0,ve.size()-1);
    }

    void QSort(vector<int>& ve,int low,int high) //�ڶ��㺯�����ݹ麯����ʵ�ַָ���������ã�
    {
        if(low<high)
        {
            int pos=partition(ve,low,high);
            QSort(ve,low,pos-1);
            QSort(ve,pos+1,high);
        }
    }

    int partition(vector<int>& ve,int low,int high)  // �����㺯�������������������ݣ�ʹve[low~high]���򣬲������м�λ�ã�
    {
        //******
        // �Ż�1:����ȡ�з���
        // ѡ��ve[0],ve[middle],ve[end]����λ�õ�����ȡ��С���м��������Ϊval
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
            swap(ve[low],ve[high]);
            while(low<high && ve[low]<=val)
                ++low;
            swap(ve[low],ve[high]);
        }
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
