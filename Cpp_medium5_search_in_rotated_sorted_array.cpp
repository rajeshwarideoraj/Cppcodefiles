class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Check if the left half is sorted
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    // Target is in the left half
                    right = mid - 1;
                } else {
                    // Target is in the right half
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]) {
                // Check if the right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    // Target is in the right half
                    left = mid + 1;
                } else {
                    // Target is in the left half
                    right = mid - 1;
                }
            } else {
                // Handle the case where nums[left] == nums[mid]
                left++;
            }
        }

        return false;
    }
};