class Solution {
// private:
//     void swapIfGreater(vector<int>& arr1, vector<int>& arr2,
//                        int ind1, int ind2) {
//         if (arr1[ind1] > arr2[ind2]) {
//             swap(arr1[ind1], arr2[ind2]);
//         }
//     }

public:
    void merge(vector<int>& arr1, int n1,
               vector<int>& arr2, int n2) {

        // int len = m + n;
        // int gap = (len + 1) / 2;

        // while (gap > 0) {

        //     int left = 0;
        //     int right = left + gap;

        //     while (right < len) {

        //         // Both in nums1
        //         if (left < m && right < m) {
        //             swapIfGreater(nums1, nums1, left, right);
        //         }

        //         // left in nums1, right in nums2
        //         else if (left < m && right >= m) {
        //             swapIfGreater(nums1, nums2, left, right - m);
        //         }

        //         // Both in nums2
        //         else {
        //             swapIfGreater(nums2, nums2,
        //                           left - m, right - m);
        //         }

        //         left++;
        //         right++;
        //     }

        //     if (gap == 1)
        //         break;

        //     gap = (gap + 1) / 2;
        // }

        // // Copy nums2 into the unused part of nums1
        // for (int i = 0; i < n; i++) {
        //     nums1[m + i] = nums2[i];

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