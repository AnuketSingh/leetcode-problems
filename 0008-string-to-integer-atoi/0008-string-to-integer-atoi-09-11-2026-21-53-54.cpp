class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int i = 0;
        int sign = 1;
        while(i < s.length() && s[i] == ' ') {
            i++;
        }
        if(i < s.length() && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < s.length() && s[i] == '+') {
            i++;
        }
        while(i < s.length() && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            if(ans * sign > INT_MAX)
                return INT_MAX;
            if(ans * sign < INT_MIN)
                return INT_MIN;
            i++;
        }
        return ans * sign;
    }
};