class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long, int> cnt;
        for (int x : planks) cnt[x]++;

        unordered_map<long long, int> t;
        int ans = 0;

        for (auto& [x, v1] : cnt) {
            // Single planks of height x
            t[x] += v1;
            ans = max(ans, t[x]);

            // Two planks of height x combined → height 2x
            t[x * 2] += v1 / 2;
            ans = max(ans, t[x * 2]);

            // Pair x with every y > x
            for (auto& [y, v2] : cnt) {
                if (y > x) {
                    t[x + y] += min(v1, v2);
                    ans = max(ans, t[x + y]);
                }
            }
        }

        return ans;
    }
};