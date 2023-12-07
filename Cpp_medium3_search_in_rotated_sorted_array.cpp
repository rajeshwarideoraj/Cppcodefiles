class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if the target is within the sorted left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    // Otherwise, search in the right half
                    left = mid + 1;
                }
            } else {
                // The right half is sorted

                // Check if the target is within the sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    // Otherwise, search in the left half
                    right = mid - 1;
                }
            }
        }

        // Target not found
        return -1;
    }
};