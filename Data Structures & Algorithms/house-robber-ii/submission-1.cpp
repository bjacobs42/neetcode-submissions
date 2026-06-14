class Solution
{
public:
    int subRob(const std::vector<int> &nums, int start, int end)
    {
        std::array<int, 2> cache;

        cache[1] = 0;
        cache[0] = nums[end - 1];
        for (int i = end - 2; i >= start; --i)
        {
            int temp = cache[0];
            cache[0] = std::max(nums[i] + cache[1], cache[0]);
            cache[1] = temp;
        }
        return (cache[0]);
    }

    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
            return (nums[0]);
            
        return (
            std::max(subRob(nums, 0, nums.size() - 1),
            subRob(nums, 1, nums.size()))
        );
    }
};
