class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> countFreq;

        for(int x : nums) {
            freq[x]++;
        }

        for(auto x : freq) {
            countFreq[x.second]++;
        }

        for(int x : nums) {
            if(countFreq[freq[x]] == 1)
                return x;
        }

        return -1;
    }
};