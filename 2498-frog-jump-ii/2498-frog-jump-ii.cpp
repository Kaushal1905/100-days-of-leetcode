class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, stones[i] - stones[i-2 >= 0 ? i-2 : i-1]);
        }

        return ans;
    }
};