/*

78. Subsets



Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


*/



class Solution {
private:

    void solve(vector<vector<int>>& ans, vector<int> output, vector<int> nums, int index){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude 
        solve(ans, output, nums, index+1);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(ans, output, nums, index+1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solve(ans, output, nums, index);

        return ans;


    }
};
