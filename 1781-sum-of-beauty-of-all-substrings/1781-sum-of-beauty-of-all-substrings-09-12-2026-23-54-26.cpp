class Solution {
public:

    int beautySum(string s) {
         int ans=0;
        for(int i=0;i<s.length();i++){
        unordered_map<char,int>mpp;
        for(int j=i;j<s.length();j++){
         mpp[s[j]]++;
        
        int maxi=INT_MIN;
        int mini=INT_MAX;
    for(auto x : mpp) {
    maxi = max(maxi, x.second);
    mini=min(mini,x.second);
    }
     ans+=(maxi-mini);
        }
        }
    
    return ans;
    }
};