class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        ans.reserve(n); // avoid repeated reallocations

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Early exit: smallest possible sum with this i is already > 0
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0)
                break;

            // Skip if largest possible sum with this i is still < 0
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0)
                continue;

            int left = i + 1, right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    int lv = nums[left], rv = nums[right];
                    while (left < right && nums[left] == lv) ++left;
                    while (left < right && nums[right] == rv) --right;
                }
                else if (sum < target) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }

        return ans;
    }
};