class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int palinCount = 0;
        std::vector<std::vector<bool>> dp (n, std::vector<bool>(n, false));

        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (s[i] != s[j] || i - j > 2 && !dp[i - 1][j + 1])
                    continue;
                dp[i][j] = true;
                ++palinCount;
            }
        }
        return (palinCount);
    }
};
