/*
989. Add to Array-Form of Integer

The array-form of an integer num is an array representing its digits in left to right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
*/


class Solution {
public:

    vector<int> reverse(vector<int> nums){
        int j = nums.size()-1;
        int i = 0;
        while(i < j){
            swap(nums[i], nums[j]);
            j--;
            i++;
        }
        return nums;
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
       
        vector<int> ans;
        int n = num.size()-1;

        int carry = k;

        while(n >= 0){
            
            int sum = num[n] + carry;
            carry = sum/10;
            sum = sum % 10;
            ans.push_back(sum);
            n--;
        }

        while(carry != 0){
            int sum = carry;
            carry = sum/10;
            sum = sum%10;
            ans.push_back(sum);
        }

        return reverse(ans);
    }
};
