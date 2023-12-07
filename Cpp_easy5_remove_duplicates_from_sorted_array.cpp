class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    // Check for edge cases
        if (nums.empty()) {
            return 0;
        }

        // Initialize a pointer for unique elements
        int uniquePointer = 0;

        // Iterate through the array
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is different from the previous one, update the pointer and update the array
            if (nums[i] != nums[uniquePointer]) {
                ++uniquePointer;
                nums[uniquePointer] = nums[i];
            }
        }

        // Return the number of unique elements
        return uniquePointer + 1;
    }
};

// Example usage:
// #include <iostream>
// int main() {
//     std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
//     Solution solution;
//     int k = solution.removeDuplicates(nums);
//     for (int i = 0; i < k; ++i) {
//         std::cout << nums[i] << " ";
//     }
//     // Output: 1 2 3 4 5
//     return 0;
// }