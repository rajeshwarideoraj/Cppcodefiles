class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        std::vector<int> result(m + n, 0);

        // Multiply each digit and add to the result
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int totalSum = mul + result[i + j + 1];
                result[i + j + 1] = totalSum % 10;
                result[i + j] += totalSum / 10;
            }
        }

        // Convert the result vector to a string
        std::string resultStr;
        for (int digit : result) {
            if (!(resultStr.empty() && digit == 0)) {
                resultStr.push_back(digit + '0');
            }
        }

        return resultStr.empty() ? "0" : resultStr;
    }
};