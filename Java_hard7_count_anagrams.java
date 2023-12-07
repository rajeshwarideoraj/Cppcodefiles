class Solution {
    public int countAnagrams(String s) {
        final int MOD = 1_000_000_007;

        // Step 1: Split the input string into an array of words
        String[] words = s.split(" ");

        // Step 2: Count the occurrences of each character in each word
        // Step 3: Use a HashMap to store the frequency of each word's signature
        Map<String, Integer> signatureCount = new HashMap<>();
        for (String word : words) {
            char[] charArray = word.toCharArray();
            Arrays.sort(charArray);
            String signature = new String(charArray);

            signatureCount.put(signature, signatureCount.getOrDefault(signature, 0) + 1);
        }

        // Step 4: Calculate the total number of distinct anagrams
        long result = 1;
        for (int count : signatureCount.values()) {
            // Use modular arithmetic to avoid overflow
            result = (result * factorial(count)) % MOD;
        }

        return (int) result;
    }

    // Helper function to calculate the factorial of a number
    private long factorial(int n) {
        long result = 1;
        for (int i = 2; i <= n; i++) {
            result = (result * i) % 1_000_000_007;
        }
        return result;
    }
}