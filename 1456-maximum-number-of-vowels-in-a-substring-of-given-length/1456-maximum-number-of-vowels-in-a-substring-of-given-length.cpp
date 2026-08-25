class Solution {
public:
    int maxVowels(string s, int k) {
        static bool vowelTable[26] = {};
        vowelTable['a' - 'a'] = vowelTable['e' - 'a'] = vowelTable['i' - 'a'] =
        vowelTable['o' - 'a'] = vowelTable['u' - 'a'] = true;

        int count = 0;
        int n = s.size();

        for (int i = 0; i < k; ++i) {
            count += vowelTable[s[i] - 'a'];
        }

        if (count == k) return k; 

        int maxCount = count;

        for (int i = k; i < n; ++i) {
            count += vowelTable[s[i] - 'a'] - vowelTable[s[i - k] - 'a'];
            if (count > maxCount) {
                maxCount = count;
                if (maxCount == k) return k; 
            }
        }

        return maxCount;
    }
};