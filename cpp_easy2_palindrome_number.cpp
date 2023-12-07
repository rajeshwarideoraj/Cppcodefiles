class Solution {
public:
    bool isPalindrome(int x) {
        // Convert the integer to a string
        std::string str_x = std::to_string(x);
        
        // Use two pointers to compare characters from the beginning and end of the string
        int left = 0, right = str_x.length() - 1;
        
        while (left < right) {
            // If characters don't match, it's not a palindrome
            if (str_x[left] != str_x[right]) {
                return false;
            }
            
            // Move the pointers towards each other
            left++;
            right--;
        }
        
        // If the loop completes, it means the integer is a palindrome
        return true;
        
    }
};