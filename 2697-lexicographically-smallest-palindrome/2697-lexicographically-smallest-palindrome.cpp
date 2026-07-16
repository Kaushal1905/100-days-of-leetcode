class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        
        while (i < j) {
            if (s[i] != s[j]) {
                char smaller = min(s[i], s[j]);
                s[i] = smaller;
                s[j] = smaller;
            }
            i++;
            j--;
        }
        
        return s;
    }
};