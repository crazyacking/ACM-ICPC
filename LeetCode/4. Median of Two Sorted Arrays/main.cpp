#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        auto it1=nums1.begin();
        auto it2=nums2.begin();
        vector<int> a;
        // merge
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

int main()
{
    Solution solution;
    int n,m,tp;
    while(cin>>n>>m)
    {
        vector<int> a,b;
        for(int i=0;i<n;++i)
        {
            cin>>tp;
            a.push_back(tp);
        }
        for(int i=0;i<m;++i)
        {
            cin>>tp;
            b.push_back(tp);
        }
//        solution.findMedianSortedArrays(a,b);
        cout<<solution.findMedianSortedArrays(a,b)<<endl;
    }
    return 0;
}
