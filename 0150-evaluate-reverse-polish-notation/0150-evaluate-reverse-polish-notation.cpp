class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        st.reserve(tokens.size()); // avoid repeated reallocation

        for (const string& token : tokens) {
            char c = token[0];
            // check operator by single-char comparison first (faster than
            // multiple string == comparisons), single-digit-safe due to length check
            if (token.size() == 1 && (c == '+' || c == '-' || c == '*' || c == '/')) {
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();
                switch (c) {
                    case '+': st.push_back(a + b); break;
                    case '-': st.push_back(a - b); break;
                    case '*': st.push_back(a * b); break;
                    case '/': st.push_back(a / b); break;
                }
            } else {
                st.push_back(stoi(token));
            }
        }

        return st.back();
    }
};