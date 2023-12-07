class Solution {
public:
    int romanToInt(string s) {
        // Create a mapping of Roman numerals to their corresponding values
        std::unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;

        // Iterate through the string from left to right
        for (int i = 0; i < s.length(); i++) {
            // Get the value of the current Roman numeral
            int currentNumeral = romanMap[s[i]];

            // Check if we need to subtract the previous numeral
            if (i > 0 && currentNumeral > romanMap[s[i - 1]]) {
                result += currentNumeral - 2 * romanMap[s[i - 1]];
            } else {
                result += currentNumeral;
            }
        }

        return result;
    }
};