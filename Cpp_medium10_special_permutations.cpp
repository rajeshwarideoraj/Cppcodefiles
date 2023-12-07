class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const int MOD = 1000000007;
        int n = nums.size();

        // Sort the array to simplify the counting process
        sort(nums.begin(), nums.end());

        // dp[i] represents the number of special permutations ending with nums[i]
        vector<int> dp(n, 1);

        // Iterate over each element in the array
        for (int i = 1; i < n; i++) {
            // For each element, check its divisibility with previous elements
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    // If divisible, update dp[i] by adding dp[j]
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
        }

        // Sum up all the values in dp array to get the total number of special permutations
        int result = 0;
        for (int count : dp) {
            result = (result + count) % MOD;
        }

        return result;
    }
};