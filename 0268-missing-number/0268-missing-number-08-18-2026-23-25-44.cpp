class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        if(nums.size()==0)
        {
            return 0;
        }
        for(int i=0;i<n;i++){
        sum=sum+nums[i];
        }
        int total=(n*(n+1)/2);
        int miss= total - sum;
        return miss;
        
    }
};