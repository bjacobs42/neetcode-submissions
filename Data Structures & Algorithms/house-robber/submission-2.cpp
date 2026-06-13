class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int                 numsSize = nums.size();
        std::array<int, 2>  profit;

        profit[0] = nums[numsSize - 1];
        profit[1] = 0;
        for (int i = numsSize - 2; i >= 0; --i)
        {
            int temp = profit[0];
            profit[0] = std::max(nums[i] + profit[1], profit[0]);
            profit[1] = temp;
        }
        return (profit[0]);
    }
};
