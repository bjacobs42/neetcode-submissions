class Solution
{
public:
    int countSubstrings(string s)
    {
        int palinCount = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size())
            {
                if (s[left] != s[right])
                    break;
                --left;
                ++right;
                ++palinCount;
            }
            
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if (s[left] != s[right])
                    break;
                --left;
                ++right;
                ++palinCount;
            }
        }
        return (palinCount);
    }
};
