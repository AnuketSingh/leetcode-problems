class Solution {
public:

    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Skip current character
            dp[i] = dp[i + 1];

            // Try every substring starting at i
            for (int j = i + k - 1; j < n; j++) {

                if (isPalindrome(s, i, j)) {
                    dp[i] = max(dp[i],
                                1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};