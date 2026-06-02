class Solution
{
public:
    int characterReplacement(string s, int k) 
    {
        std::array<int, 26> frequency {};
        int maxLen = 0;
        int maxFreq = 0;

        int left = 0;
        for (int right = 0; right < s.size(); ++right)
        {
            ++frequency[s[right] - 'A'];
            maxFreq = std::max(maxFreq, frequency[s[right] - 'A']);

            int windowSize = right - left + 1;
            if (windowSize - maxFreq > k)
            {
                --frequency[s[left] - 'A'];
                ++left;
            }
            maxLen = std::max(maxLen, right - left + 1);
        }
        return (maxLen);
    }
};
