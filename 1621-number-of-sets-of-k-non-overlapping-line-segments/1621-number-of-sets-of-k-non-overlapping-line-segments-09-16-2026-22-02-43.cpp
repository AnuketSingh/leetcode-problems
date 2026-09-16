class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;
        // dp[i][j]: ways to draw j segments using points 0..i-1
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int j = 1; j <= k; j++) {
            long long prefix = 0; // running sum of dp[m][j-1] for m = 1..i-1
            for (int i = 1; i <= n; i++) {
                dp[i][j] = (dp[i - 1][j] + prefix) % MOD;
                prefix = (prefix + dp[i][j - 1]) % MOD; // now covers m = 1..i
            }
        }

        return (int)dp[n][k];
    }
};