class Solution {
public:
    void merge(vector<int>& arr1, int n1, vector<int>& arr2, int n2) {

        vector<int> temp;
        for(int i = 0; i < n1; i++) {
            temp.push_back(arr1[i]);
        }
        for(int i = 0; i < n2; i++) {
            temp.push_back(arr2[i]);
        }
        sort(temp.begin(), temp.end());

        for(int i = 0; i < n1 + n2; i++) {
            arr1[i] = temp[i];
        }
    }
};