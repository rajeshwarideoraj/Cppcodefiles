class Solution {
public:
    int numTrees(int n) {
        if (n <= 0) {
            return 0;
        }

        // Initialize a vector to store the number of unique BSTs for each number of nodes
        std::vector<int> dp(n + 1, 0);

        // Base case: there is one unique BST with 0 nodes
        dp[0] = 1;

        // Calculate the number of unique BSTs for each number of nodes from 1 to n
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // The number of unique BSTs for i nodes is the sum of
                // the products of the number of BSTs on the left and right subtrees
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        // The result is stored in dp[n], which represents the number of unique BSTs for n nodes
        return dp[n];
    }
};