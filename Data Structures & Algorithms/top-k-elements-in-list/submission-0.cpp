class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> frequency;
        for (int n : nums)
            ++frequency[n];

        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto &[key, count] : frequency)
            buckets[count].emplace_back(key);

        std::vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int n : buckets[i]) {
                result.emplace_back(n);
                if (result.size() == k)
                    return (result);
            }
        }
        return (result);
    }
};
