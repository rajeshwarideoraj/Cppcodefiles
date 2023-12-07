class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // Initialize a 2D dp array with all elements as false
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Empty pattern matches empty string
        dp[0][0] = true;
        
        // Handle patterns with '*'
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the dp array
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char s_char = s[i - 1];
                char p_char = p[j - 1];

                if (s_char == p_char || p_char == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p_char == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s_char == p[j - 2] || p[j - 2] == '.'));
                }
            }
        }
        
        return dp[m][n];
    }
};