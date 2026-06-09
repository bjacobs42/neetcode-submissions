class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return (1);

        std::array<int, 2> step {1, 1};
        for (int i = n - 2; i >= 0; --i)
            step[i % 2] = step[0] + step[1];
        return (step[0]);
    }
};
