class Solution
{
private:
    std::vector<int> cache;
public:
    int dps(const std::vector<int>& cost, int i)
    {
        if (i >= cost.size())
            return (0);
        if (cache[i] == -1)
        {
            cache[i] = std::min(
                dps(cost, i + 1) + cost[i],
                dps(cost, i + 2) + cost[i]
            );

        }
        return (cache[i]);
    }
    
    int minCostClimbingStairs(vector<int>& cost)
    {
        cache.reserve(cost.size());
        std::fill_n(cache.begin(), cost.size(), -1);

        return (std::min(dps(cost, 0), dps(cost, 1)));
    }
};
