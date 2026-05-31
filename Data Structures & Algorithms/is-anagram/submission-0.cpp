class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return (false);

        int count[26] = {0};
        for (size_t i = 0; s[i]; ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }

        for (int char_count : count) {
            if (char_count)
                return (false);
        }
        return (true);
    }
};
