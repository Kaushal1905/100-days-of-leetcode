class Solution {
public:
    int romanToInt(string s) {
        int roman[256] = {};
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int total = 0;
        for (int i = 0; i < s.length(); i++) {
            roman[s[i]] < roman[s[i + 1]]
                ? total -= roman[s[i]]
                : total += roman[s[i]];
        }

        return total;
    }
};