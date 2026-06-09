class Solution
{
public:
    int dfs(int n, std::vector<int> &memo)
    {
        if (n <= 0)
            return (n == 0);
        if (memo[n - 1] == -1)
        {
            int oneStep = dfs(n - 1, memo);
            int twoSteps = dfs(n - 2, memo);
    
            memo[n - 1] = oneStep + twoSteps;
        }
        return (memo[n - 1]);
    }

    int climbStairs(int n)
    {
        std::vector<int>    memo(n, -1);

        return (dfs(n, memo));
    }
};
