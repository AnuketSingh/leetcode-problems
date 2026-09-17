class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        vector<int> minBestLenTillIdx(n, INT_MAX);

        int i = 0;
        int currSum = 0;

        int bestMinLen = INT_MAX;
        int result = INT_MAX;

        for (int j = 0; j < n; j++) {

            currSum += arr[j];

            while (i < j && currSum > target) {
                currSum -= arr[i];
                i++;
            }

            if (currSum == target) {

                int len = j - i + 1;

                if (i > 0 &&
                    minBestLenTillIdx[i - 1] != INT_MAX) {

                    result = min(result,
                                 len + minBestLenTillIdx[i - 1]);
                }

                bestMinLen = min(bestMinLen, len);
            }

            minBestLenTillIdx[j] = bestMinLen;
        }

        return result == INT_MAX ? -1 : result;
    }
};