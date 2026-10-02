class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> score(n + 1, 0);

        for (auto& t : trust) {
            score[t[0]]--; // trusts someone → loses a point
            score[t[1]]++; // is trusted → gains a point
        }

        for (int i = 1; i <= n; i++) {
            if (score[i] == n - 1) return i;
        }

        return -1;
    }
};