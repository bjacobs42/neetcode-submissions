class Solution {
public:
    int operation_func(int a, int b, char oper) {
        switch (oper) {
            case '+':
                return (a + b);
            case '-':
                return (a - b);
            case '*':
                return (a * b);
            case '/':
                return (a / b);
            default:
                return (0);
        }
    }

    int evalRPN(vector<string>& tokens) {
        const std::unordered_set<char> operators = {'+', '-', '*', '/'};
        std::stack<int> st;

        for (const std::string &token : tokens) {
            if (token.size() == 1 && operators.count(token[0])) {
                int a, b, result;

                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                result = operation_func(a, b, token[0]);
                st.push(result);
            } else
                st.push(std::stoi(token));
        }
        return (st.top());
    }
};
