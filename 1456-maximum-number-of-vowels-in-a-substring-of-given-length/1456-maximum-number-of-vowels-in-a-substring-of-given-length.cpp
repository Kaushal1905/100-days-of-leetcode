class Solution {
public:
    int maxVowels(string s, int k) {
        auto isV = [](char c) -> int {
            return (0x104111u >> (c - 'a')) & 1u;
        };

        const int n = s.size();
        int count = 0;

        for (int i = 0; i < k; ++i) count += isV(s[i]);
        int best = count;

        for (int i = k; i < n && best < k; ++i) {
            count += isV(s[i]) - isV(s[i - k]);
            best = max(best, count);
        }

        return best;
    }
};