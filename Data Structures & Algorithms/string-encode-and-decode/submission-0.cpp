class Solution {
private:
    const char delim = '|'; // Can't be a number
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (const string &str : strs)
            encoded += to_string(str.size()) + delim + str;
        return (encoded);
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        size_t i = 0;
        while (i < s.size()) {
            int str_len = stoi(&s[i]);
    
            i = s.find(delim, i);
            if (i == string::npos)
                break;
            ++i;
            
            decoded.push_back(s.substr(i, str_len));
            i += str_len;
        }
        return (decoded);
    }
};
