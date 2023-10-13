/*
1011. Capacity To Ship Packages Within D Days

  A conveyor belt has packages that must be shipped from one port to another within days days. We have to distribure the weights in such a manner
  that all the days are used and need to find the min load division that uses all the days. 
  
  
  Input: weights = [1,2,3,1,1], days = 4
  Output: 3
  Explanation:
  1st day: 1
  2nd day: 2
  3rd day: 3
  4th day: 1, 1


  Used Binary Search in this problem to make it easier. 
    We find the max weight load by summing the whole array. 
    Find the mid. 
  

*/

class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid){
        int day = 1;
        int load = 0;

        for(int i = 0; i < weights.size(); i++){
          // find the load limit that is lower than the mid we have.
            if(load + weights[i] <= mid){
                load += weights[i];
            }
            else{
            // once we find the max for day 1, we add the days and see if the same mid will work for the other days. 
                day++;
              // condition to check that we dont surpass the days limit and the load limit.
                if(day > days || weights[i] > mid){
                    return false;
                }
                load = weights[i];
            }
            

        }
        return true;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
        }
        int e = sum;
        int ans = -1;

        int mid = s + (e-s)/2;

        while(s<=e){
          // If it is possible to distribute the weight for a day. Meaning mid > load for the day. 
            if(isPossible(weights, days, mid)){
                ans = mid;
                e = mid - 1;
            }
          // if mid < load, then will be move the start to the front to find a load that works with out contiotion. 
            else{
                s = mid + 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};
