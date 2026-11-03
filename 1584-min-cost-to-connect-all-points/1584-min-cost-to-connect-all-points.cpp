class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> x(n), y(n), dist(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            x[i] = points[i][0];
            y[i] = points[i][1];
        }

        int cost = 0;
        int u = 0;
        dist[0] = -1;                       // -1 marks "already in MST"

        for (int it = 1; it < n; it++) {
            int next = -1, best = INT_MAX;

            // One pass: relax distances from u AND find the closest outside node
            for (int v = 0; v < n; v++) {
                if (dist[v] < 0) continue;  // skip nodes already in MST
                int d = abs(x[u] - x[v]) + abs(y[u] - y[v]);
                if (d < dist[v]) dist[v] = d;
                if (dist[v] < best) { best = dist[v]; next = v; }
            }

            cost += best;
            dist[next] = -1;
            u = next;
        }
        return cost;
    }
};
