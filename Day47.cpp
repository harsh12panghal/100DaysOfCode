/*
90. Subsets II


Given an integer array nums that may contain duplicates, return all possible
subsets
(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 
Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

*/


class Solution {
public:


    void solve(vector<vector<int>>& ans, vector<int> output, vector<int> nums, int index){
        if(index  >= nums.size()){
            if(count(ans.begin(), ans.end(), output) == 0){
                ans.push_back(output);
            }
            
            
            return;
        }
        //exclude 
        solve(ans, output, nums, index+1);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(ans, output, nums, index+1);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;

        int index = 0;

        sort(nums.begin(), nums.end());
        solve(ans, output, nums, index);
        
        return ans;
    }
};
