class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;

        vector<string> rows(numRows);
        for (string& row : rows) {
            row.reserve(n / numRows + 2); // avoid repeated reallocations
        }

        int curRow = 0;
        int direction = -1; // will flip to +1 on first char

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                direction = -direction;
            }
            curRow += direction;
        }

        string result;
        result.reserve(n);
        for (string& row : rows) {
            result += row;
        }

        return result;
    }
};