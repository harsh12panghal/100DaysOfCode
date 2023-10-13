/*
16. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.
You may assume that each input would have exactly one solution.
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        
        int ans;
        int diff = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int j = i+1; 
            int k = nums.size()-1;
            int sum;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];

                if(sum == target)
                    return sum;
                else if(abs(target-sum) < diff){
                    diff = abs(target-sum);
                    ans = sum;
                }

                if(sum > target)
                    k--;
                else
                    j++;
            
            
            }

            
        }
        return ans;
    }
};
