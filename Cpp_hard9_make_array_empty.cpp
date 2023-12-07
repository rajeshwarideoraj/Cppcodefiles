class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::vector<int> sortedNums = nums;
        std::sort(sortedNums.begin(), sortedNums.end());

        int minIndex = 0;
        long long operations = 0;

        for (int num : nums) {
            if (num == sortedNums[minIndex]) {
                minIndex++;
            } else {
                operations++;
            }
        }

        return operations;
    }
};