class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        char* p = s.data();      // raw pointer, avoids operator[] bounds-check overhead
        int i = 0, j = n - 1;
        
        while (i < j) {
            char a = p[i], b = p[j];
            if (a != b) {
                char smaller = (a < b) ? a : b;  // avoid std::min call/template overhead
                p[i] = smaller;
                p[j] = smaller;
            }
            ++i;
            --j;
        }
        
        return s;
    }
};