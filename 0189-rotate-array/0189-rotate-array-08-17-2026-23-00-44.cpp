class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n=arr.size();
       
        vector<int>nums(n);
        for(int i =0 ; i<n ; i++){
            int idx = (i+k)%n;
            nums[idx] = arr[i];

        }
       for(int i =0 ; i<n ; i++){
          arr[i] = nums[i];
       }
        
    }
};
    