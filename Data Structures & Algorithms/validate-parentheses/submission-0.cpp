class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> pairs = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        std::stack<char> order;

        for (char c : s) {
            if (pairs.find(c) != pairs.end())
                order.push(c);
            else if (!order.size() || pairs[order.top()] != c)
                return (false);
            else
                order.pop();
        }
        return (!order.size());
    }
};
