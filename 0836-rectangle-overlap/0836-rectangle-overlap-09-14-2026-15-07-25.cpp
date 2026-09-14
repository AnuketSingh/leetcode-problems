class Solution {
public:
    bool isRectangleOverlap(vector<int>& X1, vector<int>& X2) {
        return (X1[0]<X2[2]&&X1[2]>X2[0]&&X1[1]<X2[3]&&X2[1]<X1[3]);
    }
};