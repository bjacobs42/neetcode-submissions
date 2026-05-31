class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::array<int, 128>  seen; // all ASCII characters last seen position
        seen.fill(-1);
        int maxLen = 0;
        
        int end;
        int start = 0;
        for (end = 0; s[end]; ++end)
        {
            char c = s[end];

            if (seen[c] >= start)
            {
                maxLen = std::max(maxLen, end - start);
                start = seen[c] + 1;
            }
            seen[c] = end;
        }
        return (std::max(maxLen, end - start));
    }
};
