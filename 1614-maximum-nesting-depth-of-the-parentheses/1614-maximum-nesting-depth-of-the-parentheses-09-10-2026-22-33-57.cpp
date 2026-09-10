class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int ans=0;
        for(char ch :s){
            if(ch=='('){
               count++;
               ans=max(count,ans); 
            }
            else if(ch==')'){
                count--;
            }
        }
        return ans;
    }
};