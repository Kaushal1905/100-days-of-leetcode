class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i = 0, j = (int)s.size() - 1;
        
        while (i < j) {
            if (s[i] != s[j]) {
                char smaller = min(s[i], s[j]);
                s[i] = s[j] = smaller;
            }
            i++;
            j--;
        }
        
        return s;
    }
};