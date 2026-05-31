class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        std::array<int, 26> s1_count = {};
        std::array<int, 26> s2_count = {};
        for (char c : s1)
            ++s1_count[c - 'a'];
        
        int left = 0;
        for (int right = 0; right < s2.size(); ++right)
        {
            char c_index = s2[right] - 'a';

            ++s2_count[c_index];
            while (s2_count[c_index] > s1_count[c_index])
            {
                --s2_count[s2[left] - 'a'];
                ++left;
            }
            if (right - left + 1 == s1.size())
                return (true);
        }
        return (false);
    }
};
