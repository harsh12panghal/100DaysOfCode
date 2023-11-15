/* 
47. Permutations II


Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

*/


class Solution {
public:

    
    void solve(vector<vector<int>> & ans, vector<int> nums, int index){
        if(index >= nums.size()){
            

            ans.push_back(nums);
            return;
            
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            
            bool isPresent = find(ans.begin(), ans.end(), nums) != ans.end();
            if(isPresent){
                continue;
            }

            solve(ans, nums, index+1);
            swap(nums[i], nums[index]);
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        sort(nums.begin(), nums.end());
        solve(ans, nums, index);

        return ans;

    }
};
