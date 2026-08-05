class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int MOD = 1e9 + 7;
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<pair<int, int>> q;
        vector<int> visited(n + 1, 0);
        q.push({1, 0});
        visited[1] = 1;
        int maxDepth = 0;
        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            maxDepth = max(maxDepth, depth);
            for (int child : adj[node]) {
                if (!visited[child]) {
                    visited[child] = 1;
                    q.push({child, depth + 1});
                }
            }
        }

        long long ans = 1;

        for (int i = 1; i < maxDepth; i++) {
            ans = (ans * 2) % MOD;
        }

        return ans;
    }
};