class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int R = heights.size(), C = heights[0].size();
        vector<int> dist(R * C, INT_MAX);
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq; // {effort, r, c}

        dist[0] = 0;
        pq.push({0, 0, 0});
        const int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [e, r, c] = pq.top(); pq.pop();
            if (r == R - 1 && c == C - 1) return e;   // first pop of target is optimal
            if (e > dist[r * C + c]) continue;        // stale entry

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                int ne = max(e, abs(heights[nr][nc] - heights[r][c]));
                if (ne < dist[nr * C + nc]) {
                    dist[nr * C + nc] = ne;
                    pq.push({ne, nr, nc});
                }
            }
        }
        return 0;
    }
};