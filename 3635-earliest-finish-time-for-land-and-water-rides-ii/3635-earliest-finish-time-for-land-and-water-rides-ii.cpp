class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        return min(
            solve(landStartTime, landDuration, waterStartTime, waterDuration),
            solve(waterStartTime, waterDuration, landStartTime, landDuration)
        );
    }

    int solve(vector<int>& start1, vector<int>& dur1,
              vector<int>& start2, vector<int>& dur2) {
        
        int n = start1.size();
        int m = start2.size();

        vector<pair<int, int>> rides2;

        for (int i = 0; i < m; i++) {
            rides2.push_back({start2[i], dur2[i]});
        }

        sort(rides2.begin(), rides2.end());

        vector<int> starts(m);
        vector<int> prefixMinDur(m);
        vector<int> suffixMinEnd(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides2[i].first;

            if (i == 0)
                prefixMinDur[i] = rides2[i].second;
            else
                prefixMinDur[i] = min(prefixMinDur[i - 1], rides2[i].second);
        }

        for (int i = m - 1; i >= 0; i--) {
            int endTime = rides2[i].first + rides2[i].second;

            if (i == m - 1)
                suffixMinEnd[i] = endTime;
            else
                suffixMinEnd[i] = min(suffixMinEnd[i + 1], endTime);
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int finishFirst = start1[i] + dur1[i];

            int idx = upper_bound(starts.begin(), starts.end(), finishFirst) - starts.begin();

            if (idx > 0) {
                ans = min(ans, finishFirst + prefixMinDur[idx - 1]);
            }

            if (idx < m) {
                ans = min(ans, suffixMinEnd[idx]);
            }
        }

        return ans;
    }
};