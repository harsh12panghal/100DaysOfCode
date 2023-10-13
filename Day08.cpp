/*
88. Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.

*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      
        int i = 0;
        for(int j = m; j < m+n; j++){
            if(nums1[j] == 0){
                nums1[j] = nums2[i];
                i++;
            }
        }


        sort(nums1.begin(), nums1.end());
    }
};
