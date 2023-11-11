/*
17. Letter Combinations of a Phone Number



Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


*/


class Solution {
public:

    void solve( vector<string>& ans, string output, string digits, string mapping[], int index){
        if(index >= digits.length()){

            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i = 0; i < value.length(); i++){
            output.push_back(value[i]);
            solve(ans, output, digits, mapping, index+1);
            output.pop_back();

        }
        

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        int index = 0;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        if(digits.length() == 0){
            return ans;
        }

        solve(ans, output, digits, mapping, index);

        return ans;

    }
};
