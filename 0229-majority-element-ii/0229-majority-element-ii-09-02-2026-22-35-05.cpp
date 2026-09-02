class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int>list;
      map<int,int>mpp;  
      int n=nums.size();
      int mm= n/3+1;
      for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]]==mm){
            list.push_back(nums[i]);
        }
        if(list.size()==2)
            break;
      }
      sort(list.begin(),list.end());
      return list;

    }
};