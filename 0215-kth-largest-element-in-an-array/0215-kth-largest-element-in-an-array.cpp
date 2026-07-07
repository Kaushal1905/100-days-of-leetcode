class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int targetIdx = n - k; // index of kth largest in ascending sorted order
        int left = 0, right = n - 1;

        while (left < right) {
            auto [lt, gt] = partition3Way(nums, left, right);

            if (targetIdx < lt) {
                right = lt - 1;
            } else if (targetIdx > gt) {
                left = gt + 1;
            } else {
                // targetIdx is within the "equal to pivot" band
                return nums[targetIdx];
            }
        }
        return nums[left];
    }

private:
    // 3-way partition: returns [lt, gt] such that
    // nums[left..lt-1] < pivot, nums[lt..gt] == pivot, nums[gt+1..right] > pivot
    pair<int,int> partition3Way(vector<int>& nums, int left, int right) {
        int randIdx = left + rand() % (right - left + 1);
        int pivot = nums[randIdx];

        int lt = left, i = left, gt = right;

        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[lt++], nums[i++]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt--]);
            } else {
                i++;
            }
        }
        return {lt, gt};
    }
};