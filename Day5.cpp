/*

33. Search in Rotated Sorted Array

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

*/



class Solution {
public:

    int findPivot(vector<int> &nums, int n){
        int s = 0;
        int e = n-1;

        int mid = s + (e-s)/2;

        while(s < e){
            if(nums[mid] >= nums[0]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }

    int binarySearch(vector<int>& nums, int start, int end, int target){
        int s = start;
        int e = end;
        int mid = s + (e-s)/2;
        int k = target;

        while(s<=e){
            if(nums[mid] == k){
                return mid;
            }
            if(nums[mid] > k){
                e = mid -1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = findPivot(nums, n);

        if(target >= nums[pivot] && target <=  nums[n-1])
            return binarySearch(nums, pivot, n-1, target);
        else
            return binarySearch(nums, 0, pivot, target);

    }
};
