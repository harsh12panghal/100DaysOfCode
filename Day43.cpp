/*
39. Combination Sum


Given an array of distinct integers candidates and a target integer target, return a list of
all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Explanation:

2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

*/



class Solution {
public:
    // [7,5,8,12,3,10,9,4,11,6]
    void solve(vector<vector<int>>& ans, vector<int> sum, vector<int> nums, int target, int index){

    if(target == 0){
        ans.push_back(sum);
        return;
    }
    if(target < 0 || index >= nums.size()){
        return;
    }

    //we will keep adding the index until the target becomes either 0 or becomes negative 
    sum.push_back(nums[index]);
    solve(ans, sum, nums, target - nums[index], index); //target se minus karte rehena hai 
   
   //once we find that the target becomes negative then last dig pop_back karte increase the index
    sum.pop_back();
    solve(ans, sum, nums, target, index + 1);


    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sum;
        int index = 0;

        solve(ans, sum, candidates, target, index);

        return ans;
    }
};
