class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (const string& s : words) {
            int left = 0, right = (int)s.size() - 1;
            while (left < right && s[left] == s[right]) {
                left++;
                right--;
            }
            if (left >= right) {
                return s;
            }
        }
        return "";
    }
};