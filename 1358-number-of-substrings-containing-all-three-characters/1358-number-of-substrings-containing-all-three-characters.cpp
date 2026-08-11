class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[3] = {-1, -1, -1}; // last seen index of 'a', 'b', 'c'
        long long res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
            int minLast = min({last[0], last[1], last[2]});
            if (minLast != -1) {
                res += minLast + 1;
            }
        }
        
        return (int)res;
    }
};