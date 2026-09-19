class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        window.reserve(min((size_t)k + 1, nums.size()));
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                window.erase(nums[i - k - 1]);   
            }
            if (!window.insert(nums[i]).second) {
                return true;                      
            }
        }
        return false;
    }
};