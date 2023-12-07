class Solution {
public:
    bool isNumber(string s) {
       if (s.empty()) {
            return false;
        }

        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;

        // Iterate through each character in the string
        for (char c : s) {
            // Check for digits
            if (std::isdigit(c)) {
                seenDigit = true;
            }
            // Check for '+' or '-'
            else if (c == '+' || c == '-') {
                // Must be the first character or must be after 'e' or 'E'
                if (!s.empty() && s.back() != 'e' && s.back() != 'E') {
                    return false;
                }
            }
            // Check for dot '.'
            else if (c == '.') {
                // Must not have seen dot before and must not have seen 'e' or 'E'
                if (seenDot || seenE) {
                    return false;
                }
                seenDot = true;
            }
            // Check for 'e' or 'E'
            else if (c == 'e' || c == 'E') {
                // Must not have seen 'e' or 'E' before, and there must be at least one digit before 'e' or 'E'
                if (seenE || !seenDigit) {
                    return false;
                }
                seenE = true;
                seenDigit = false; // Reset seenDigit for the digits after 'e' or 'E'
            }
            // Any other character is invalid
            else {
                return false;
            }
        }

        // The number must end with a digit
        return seenDigit; 
    }
};