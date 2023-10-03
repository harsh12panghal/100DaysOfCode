/*
  852. Peak Index in a Mountain Array
  
  Given an array we have to find the peak element of the array.
  Ex.
  Input: arr = [0,1,0]
  Output: 1
  To solve this, I used the binary search concept.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0; 
        int e = arr.size() -1;
        int mid = (s+e)/2;

        while(s<e){
            if(arr[mid] < arr[mid+1])
                s = mid+1;
            else
                e = mid;
            mid = (s+e)/2;
        }
        return s;
    }
};
