class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        std::array<int, 2> cache;
        if (n < 2)
            return (s[n - 1] != '0');

        cache[1] = s[n - 1] != '0';
        cache[0] = s[n - 2] != '0';
        if (cache[0] && (s[n - 2] - '0') * 10 + s[n - 1] - '0' <= 26)
            cache[0] += cache[1];
        
        for (int i = n - 3; i >= 0; --i)
        {
            int tmp = cache[0];

            if (s[i] == '0')
                cache[0] = 0;
            else if ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26)
                cache[0] += cache[1];
            cache[1] = tmp;
        }
        return (cache[0]);
    }
};