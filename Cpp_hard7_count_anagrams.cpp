class Solution {
public:
    int countAnagrams(string s) {
        const int MOD = 1000000007;

        // Split the input string into words
        std::vector<std::string> words;
        size_t start = 0;
        size_t end = s.find(' ');

        while (end != std::string::npos) {
            words.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(' ', start);
        }
        words.push_back(s.substr(start, end));

        // Count the occurrences of each word signature
        std::unordered_map<std::string, int> signatureCount;
        for (const std::string& word : words) {
            std::string signature = word;
            std::sort(signature.begin(), signature.end());
            signatureCount[signature]++;
        }

        // Calculate the number of anagrams for each word
        long long result = 1;
        for (const auto& entry : signatureCount) {
            int count = entry.second;
            long long factorial = 1;

            // Calculate factorial(count)
            for (int i = 2; i <= count; ++i) {
                factorial = (factorial * i) % MOD;
            }

            result = (result * factorial) % MOD;
        }

        return static_cast<int>(result);
    }
};