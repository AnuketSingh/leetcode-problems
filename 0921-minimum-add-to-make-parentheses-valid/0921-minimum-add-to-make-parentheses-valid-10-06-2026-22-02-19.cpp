class Solution {
public:
    int minAddToMakeValid(string s) {
       int n=s.length();
       int ans=0; 
       int count=0;
       for(int i=0;i<n;i++) {
           if(s[i]=='('){
               count++;
           }
           else {
               if(count>0) count--;
               else ans++;
           }
       }
       ans+=count;
       return ans;
    }
};