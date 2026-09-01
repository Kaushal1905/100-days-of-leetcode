class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for (int num : nums) {
            g = __gcd(g, num);
            if (g == 1) return true; // early exit — GCD can never improve beyond 1
        }
        return g == 1;
    }
};