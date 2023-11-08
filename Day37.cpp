/*
704. Binary Search with recursion 

Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/


class Solution {
public:
    int binarySearch(vector<int>& arr, int s, int e, int target){
        if(s > e)
            return -1;
        
        int mid = s + (e-s)/2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target){
            int ans = binarySearch(arr, s, mid-1, target);
            return ans;
        }
        else{
            int ans = binarySearch(arr, mid+1, e, target);
            return ans;
        }
        
    }


    int search(vector<int>& nums, int target) {
        int s = 0; 
        int e = nums.size()-1;
        
        int ans = binarySearch(nums, s, e, target);
        return ans;
    }
};
