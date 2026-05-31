class Solution {
public:
    std::string count_freq(const string &str) {
        std::string frequency(26, 0);
        for (char c : str)
            ++frequency[c - 'a'];
        return (frequency);
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (const std::string &str : strs) {
            std::string key = count_freq(str);
            groups[key].emplace_back(str);
        }

        std::vector<std::vector<std::string>>   result;
        for (const auto&[key, strs] : groups)
            result.emplace_back(strs);
        return (result);
    }
};
