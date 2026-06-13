class Solution
{
private:
    std::vector<int> cache;
public:
    int dfs(std::vector<int>& nums, int i)
    {
        if (i >= nums.size())
            return (0);
        
        if (cache[i] == -1)
            cache[i] = std::max(dfs(nums, i + 1), dfs(nums, i + 2) + nums[i]);
        return (cache[i]);
    }
    int rob(vector<int>& nums)
    {
        std::cout << nums.size() << std::endl;
        cache.reserve(nums.size());
        std::fill_n(cache.begin(), nums.size(), -1);
        return (dfs(nums, 0));
    }
};
