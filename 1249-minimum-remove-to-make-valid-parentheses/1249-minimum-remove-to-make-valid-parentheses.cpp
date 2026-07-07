class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp;
        int open = 0;

        // Remove invalid ')'
        for (char c : s) {
            if (c == '(') {
                open++;
                temp += c;
            }
            else if (c == ')') {
                if (open > 0) {
                    open--;
                    temp += c;
                }
            }
            else {
                temp += c;
            }
        }

        string ans;

        // Remove extra '(' from right to left
        for (int i = temp.size() - 1; i >= 0; i--) {
            if (temp[i] == '(' && open > 0) {
                open--;
                continue;
            }
            ans += temp[i];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};