class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.length() < 2) {
            return s;
        }

        int n = s.length();
        int start = 0;  // Start index of the longest palindromic substring
        int maxLen = 1; // Length of the longest palindromic substring

        // Function to expand around the center and find palindrome
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };

        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(i, i);      // Odd length palindrome
            int len2 = expandAroundCenter(i, i + 1);  // Even length palindrome

            // Find the maximum length palindrome centered at i
            int currMaxLen = max(len1, len2);

            if (currMaxLen > maxLen) {
                maxLen = currMaxLen;
                start = i - (currMaxLen - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};