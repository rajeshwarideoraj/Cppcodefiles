class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const int MOD = 1e9 + 7;
        long long maxProduct = 0;

        for (long long x = 0; x < pow(2, n); x++) {
            long long xorA = a ^ x;
            long long xorB = b ^ x;
            long long product = (xorA % MOD) * (xorB % MOD) % MOD;
            maxProduct = std::max(maxProduct, product);
        }

        return static_cast<int>(maxProduct);
    }
};