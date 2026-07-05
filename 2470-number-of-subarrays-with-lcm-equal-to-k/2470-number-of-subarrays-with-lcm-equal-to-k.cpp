class Solution {
public:
    long long lcm(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }
    
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        
        // dp: maps {LCM value -> number of subarrays ending at previous index with that LCM}
        unordered_map<long long, long long> dp;
        
        for (int j = 0; j < n; j++) {
            unordered_map<long long, long long> newDp;
            
            if (k % nums[j] == 0) {
                // Start a new subarray at j
                newDp[nums[j]] += 1;
                
                // Extend all subarrays ending at j-1
                for (auto& [val, cnt] : dp) {
                    long long l = lcm(val, nums[j]);
                    if (k % l == 0) {  // prune anything that can't lead to k
                        newDp[l] += cnt;
                    }
                }
            }
            
            dp = newDp;
            if (dp.count(k)) count += dp[k];
        }
        
        return count;
    }
};