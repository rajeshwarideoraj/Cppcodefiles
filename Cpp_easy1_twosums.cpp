class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create an unordered_map to store the difference between target and each element
        std::unordered_map<int, int> complementMap;

        // Iterate through the vector
        for (int i = 0; i < nums.size(); ++i) {
            int currentNum = nums[i];
            int complement = target - currentNum;

            // Check if the complement is already in the map
            auto it = complementMap.find(complement);
            if (it != complementMap.end()) {
                // If found, return the indices of the two numbers
                return {it->second, i};
            }

            // If complement is not found, add the current number and its index to the map
            complementMap[currentNum] = i;
        }

        // If no solution is found, return an empty vector
        return {};
        
    }
};