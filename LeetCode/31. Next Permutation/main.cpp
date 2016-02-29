class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        if(next_permutation(nums.begin(),nums.end()))
            return;
        else
        {
            sort(nums.begin(),nums.end());
            return;
        }
    }
};
