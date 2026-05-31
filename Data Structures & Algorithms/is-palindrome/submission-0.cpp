class Solution {
public:
    bool isPalindrome(string s) {
        std::string::iterator left = s.begin();
        std::string::iterator right = s.end() - 1;

        while (left < right) {
            while (left < right && !std::isalnum(*left))
                ++left;
            while (left < right && !std::isalnum(*right))
                --right;
            if (std::tolower(*left) != std::tolower(*right))
                return (false);
            ++left;
            --right;
        }
        return (true);
    }
};
