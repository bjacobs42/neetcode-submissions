class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        int maxLen = 0;
        std::unordered_set<int> counts(nums.begin(), nums.end());
        
        for (int n : nums)
        {
            if (!counts.count(n - 1))
            {
                int i = 1;
                while (counts.count(n + i))
                    ++i;
                maxLen = std::max(maxLen, i);
            }
        }
        return (maxLen);
    }
};
