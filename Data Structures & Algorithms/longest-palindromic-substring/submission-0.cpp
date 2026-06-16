class Solution
{
public:
    bool isPalindrome(std::string s, int start, int end)
    {
        --end;
        while (start <= end)
        {
            if (s[start] != s[end])
                return (false);
            ++start;
            --end;
        }
        return (true);
    }
    string longestPalindrome(string s)
    {
        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = s.size() - 1; i < j; --j)
            {
                if (j + 1 - i <= maxLen)
                    break;
                if (s[j] == s[i] && isPalindrome(s, i, j + 1))
                {
                    start = i;
                    maxLen = j + 1 - i;
                }
            }
        }
        return (s.substr(start, maxLen));
    }
};
