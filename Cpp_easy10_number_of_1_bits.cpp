class Solution {
public:
    int hammingWeight(uint32_t n) {
       int count = 0;
        
        while (n != 0) {
            count += n & 1; // Check the rightmost bit
            n >>= 1;       // Right shift the bits
        }
        
        return count; 
    }
};