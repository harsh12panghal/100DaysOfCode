/*
46. Permutations


Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/



class Solution {
public:


    void solve(vector<vector<int>>& ans, vector<int> output, vector<int> nums, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(ans, output, nums, index+1);
            swap(nums[i], nums[index]);
        }
    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output; 
        int index = 0;

        solve(ans, output, nums, index);

        return ans;
    }
};
