/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-03-12.07
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

/*Solution 1*/
class Solution
{
    //求A和B数组的第k大数
    int getMedian(int A[], int m, int B[], int n,int k)
    {
        if(m>n)
            return getMedian(B,n,A,m,k); //默认A为短数组
        if(m==0)
            return B[k-1];
        if(k==1)
            return min(A[0], B[0]);
        int pa = min(k/2, m);
        int pb = k - pa;
        if(A[pa-1] < B[pb-1])
        {
            return getMedian(A+pa, m-pa, B, n, k-pa);
        }
        else if(A[pa-1] > B[pb-1])
        {
            return getMedian(A, m, B+pb, n-pb, k-pb);
        }
        else
        {
            return A[pa-1];
        }
        return 0;
    }
public:
    double work(int A[], int m, int B[], int n)
    {
        if((m+n)%2 == 0)
        {
            return (getMedian(A, m,B, n, (m+n)/2) + getMedian(A, m,B, n, (m+n)/2+1)) /2.;
        }
        else
        {
            return getMedian(A, m,B, n, (m+n)/2+1);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int A[10000],B[10000];
        int idx=0;
        for(auto p:nums1)
        {
            A[idx++]=p;
        }
        idx=0;
        for(auto p:nums2)
        {
            B[idx++]=p;
        }
        int m=nums1.size();
        int n=nums2.size();
        double ret=work(A,m,B,n);
        return ret;
    }
};

/*Solution 2*/
/*
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        auto it1=nums1.begin();
        auto it2=nums2.begin();
        vector<int> a;
        while(it1!=nums1.end() || it2!=nums2.end())
        {
            if(it1==nums1.end() && it2!=nums2.end())
            {
                a.push_back((*it2));
                it2++;
            }
            else if(it1!=nums1.end() && it2==nums2.end())
            {
                a.push_back(*it1);
                it1++;
            }
            else if(it1!=nums1.end() && it2!=nums2.end())
            {
                if((*it1)<(*it2))
                {
                    a.push_back(*it1);
                    it1++;
                }
                else
                {
                    a.push_back(*it2);
                    it2++;
                }
            }
        }
        int len=a.size();
        double ans=(len%2)?(double)a[len/2]:(double)(a[len/2-1]+a[len/2])/2.;
        return ans;
    }
};
*/

int main()
{
      int n,m,temp;
      while(cin>>n>>m)
      {
          vector<int> a,b;
          for(int i=0;i<n;++i)
          {
              cin>>temp;
              a.push_back(temp);
          }
          for(int i=0;i<m;++i)
          {
              cin>>temp;
              b.push_back(temp);
          }
          Solution solution;
          double ans=solution.findMedianSortedArrays(a,b);
          cout<<"===========ans==========="<<endl;
          cout<<ans<<endl;
      }
      return 0;
}
