class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int curRow = 0;
        int direction = -1;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                direction = -direction;
            }
            curRow += direction;
        }

        string result;
        result.reserve(s.size());
        for (string& row : rows) {
            result += row;
        }

        return result;
    }
};