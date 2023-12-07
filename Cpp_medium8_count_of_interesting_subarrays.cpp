class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long result = 0;

        for (int l = 0; l < n; l++) {
            int cnt = 0;

            for (int r = l; r < n; r++) {
                if (nums[r] % modulo == k) {
                    cnt++;
                }

                if (cnt % modulo == k) {
                    result++;
                }
            }
        }

        return result;
    }
};