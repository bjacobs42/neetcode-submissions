class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        std::array<int, 2> cache{cost.back(), 0};

        for (int i = cost.size() - 2; i >= 0; --i)
        {
            int temp = cache[0];
            cache[0] = cost[i] + std::min(cache[0], cache[1]);
            cache[1] = temp;
        }
        return (std::min(cache[0], cache[1]));
    }
};
