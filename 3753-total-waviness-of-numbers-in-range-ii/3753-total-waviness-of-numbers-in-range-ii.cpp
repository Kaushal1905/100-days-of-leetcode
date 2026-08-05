class Solution {
public:
    using ll = long long;

    struct Ans {
        ll count;
        ll sum;
    };

    string s;
    Ans dp[20][11][11][3];
    bool vis[20][11][11][3];

    Ans solve(int pos, int prev2, int prev1, int len, bool tight) {
        if (pos == s.size()) {
            return {len > 0 ? 1 : 0, 0};
        }

        if (!tight && vis[pos][prev2][prev1][len])
            return dp[pos][prev2][prev1][len];

        int limit = tight ? s[pos] - '0' : 9;
        Ans res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            if (len == 0 && d == 0) {
                Ans next = solve(pos + 1, 10, 10, 0, newTight);
                res.count += next.count;
                res.sum += next.sum;
            } 
            else if (len == 0) {
                Ans next = solve(pos + 1, 10, d, 1, newTight);
                res.count += next.count;
                res.sum += next.sum;
            } 
            else if (len == 1) {
                Ans next = solve(pos + 1, prev1, d, 2, newTight);
                res.count += next.count;
                res.sum += next.sum;
            } 
            else {
                int add = 0;

                if (prev1 > prev2 && prev1 > d) add = 1; // peak
                if (prev1 < prev2 && prev1 < d) add = 1; // valley

                Ans next = solve(pos + 1, prev1, d, 2, newTight);

                res.count += next.count;
                res.sum += next.sum + add * next.count;
            }
        }

        if (!tight) {
            vis[pos][prev2][prev1][len] = true;
            dp[pos][prev2][prev1][len] = res;
        }

        return res;
    }

    ll getSum(ll n) {
        if (n <= 0) return 0;

        s = to_string(n);
        memset(vis, false, sizeof(vis));

        return solve(0, 10, 10, 0, true).sum;
    }

    ll totalWaviness(ll num1, ll num2) {
        return getSum(num2) - getSum(num1 - 1);
    }
};