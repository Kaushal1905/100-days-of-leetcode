class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // BFS from root (node 1) to find max depth
        int maxDepth = 0;
        vector<int> depth(n + 1, -1);
        queue<int> q;
        q.push(1);
        depth[1] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            maxDepth = max(maxDepth, depth[node]);
            for (int nb : adj[node]) {
                if (depth[nb] == -1) {
                    depth[nb] = depth[node] + 1;
                    q.push(nb);
                }
            }
        }

        if (maxDepth == 0) return 0;

        // Answer = 2^(maxDepth - 1) % MOD
        long long ans = 1, base = 2;
        int exp = maxDepth - 1;
        while (exp > 0) {
            if (exp & 1) ans = ans * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }

        return (int)ans;
    }
};