class Solution {
public:
    int countValidPrefixes(string s) {
        int count0 = 0, count1 = 0, ans = 0;
        for (char ch : s) {
            if (ch == '0') count0++;
            else count1++;
            if (abs(count0 - count1) <= 1) ans++;
        }
        return ans;
    }
};