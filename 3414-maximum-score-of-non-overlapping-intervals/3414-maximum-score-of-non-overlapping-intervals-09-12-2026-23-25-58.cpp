class Solution {
public:

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // start, end, weight, original index
        vector<array<long long, 4>> a;

        for(int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort according to ending time
        sort(a.begin(), a.end(),
            [](auto &x, auto &y) {
                return x[1] < y[1];
            });

        // dp[i][k]
        // best answer using first i intervals
        // and choosing at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for(int i = 1; i <= n; i++) {

            // Don't take current interval
            for(int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i-1][k];
            }

            // --------------------------------
            // Binary search previous interval
            // --------------------------------

            int low = 0;
            int high = i - 2;
            int j = -1;

            while(low <= high) {

                int mid = low + (high - low) / 2;

                if(a[mid][1] < a[i-1][0]) {
                    j = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            // --------------------------------
            // Take current interval
            // --------------------------------

            for(int k = 1; k <= 4; k++) {

                pair<long long, vector<int>> take;

                if(j == -1) {
                    take = dp[0][k-1];
                }
                else {
                    take = dp[j+1][k-1];
                }

                take.first += a[i-1][2];

                take.second.push_back(a[i-1][3]);

                sort(take.second.begin(), take.second.end());

                // Better score
                if(take.first > dp[i][k].first) {
                    dp[i][k] = take;
                }

                // Same score -> lexicographically smaller
                else if(take.first == dp[i][k].first &&
                        take.second < dp[i][k].second) {

                    dp[i][k] = take;
                }
            }
        }

        return dp[n][4].second;
    }
};