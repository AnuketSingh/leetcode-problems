class Solution {
public:
    vector<string>result;
    bool isValid(string & str) {
        int count = 0;
        for (char& ch : str) {
            if (ch == '(')
                count++;
            else
                count--;
            if (count < 0)
                return false;
        }
        return count == 0;
    }
    void Solve(string& Curr, int n) {
        if (Curr.length() == 2*n) {
            if (isValid(Curr)) {
                result.push_back(Curr);
            }
            return;
        }
         Curr.push_back('(');
        Solve(Curr, n);
        Curr.pop_back();
        Curr.push_back(')');
        Solve(Curr, n);
        Curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string Curr = "";
        Solve(Curr, n);
        return result;
    }
};