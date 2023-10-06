/*
912. Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Input: nums = [5,2,3,1]
Output: [1,2,3,5]

Used the merge sort algo with recursion to solve this perticular problem. 
*/



class Solution {
public:

    void merge(vector<int>& arr, int s, int e){
        int mid = s + (e-s)/2;

        int len1 = mid - s +1;
        int len2 = e - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        //copy value

        int mainArrayIndex = s;
        for(int i = 0; i < len1; i++){
            first[i] = arr[mainArrayIndex++];
        }

        mainArrayIndex = mid + 1;
        for(int i = 0; i < len2; i++){
            second[i] = arr[mainArrayIndex++];
        }

        //merge
        int index1 = 0;
        int index2 = 0;

        mainArrayIndex = s;
        while(index1 < len1 && index2 < len2){
            if(first[index1] < second[index2]){
                arr[mainArrayIndex++] = first[index1++];
            }
            else{
                 arr[mainArrayIndex++] = second[index2++];
            }
        }
        while(index1 < len1){
             arr[mainArrayIndex++] = first[index1++];
        }
        while(index2 < len2){
             arr[mainArrayIndex++] = second[index2++];
        }

    }

    void mergeSort(vector<int>& nums, int s, int e){
        if(s >= e)
            return;

        int mid = s + (e-s)/2;
        //merge left part 
        mergeSort(nums, s, mid);

        //merge right part 
        mergeSort(nums, mid+1, e);

        //merge
        merge(nums, s, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size()-1;
        mergeSort(nums, 0, n);

        return nums;
    }
};
