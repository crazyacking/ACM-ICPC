#include <bits/stdc++.h>
using namespace std;


void debug(list<int> nums)
{
    for(auto p:nums)
        cout<<p<<" ";
    cout<<endl;
}

void delete_k_number(list<int>& nums,int n,int k)
{
    int cnt=0;
    list<int>::iterator lit,rit;
    lit=rit=nums.begin();
    rit++;
    while(cnt<k && rit!=nums.end())
    {
        if(*lit < *rit)
        {
            nums.erase(lit);
//            debug(nums);
            lit=rit++;
            ++cnt;
        }
        else
            ++lit,++rit;
    }
    if(cnt<k)
    {
        int gap=k-cnt;
        while(gap--)
            nums.pop_back();
    }
    for(auto p:nums)
        cout<<p<<" ";
    cout<<endl;
}

int main()
{
    int n,k,val;
    while(cin>>n>>k)
    {
        list<int> nums;
        for(int i=0; i<n; ++i)
        {
            cin>>val;
            nums.push_back(val);
        }
        delete_k_number(nums,n,k);
    }
    return 0;
}
