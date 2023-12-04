/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.


*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        unordered_map<char, int> map;
        int maxl = 0;
        int left = 0;


        for(int right = 0; right < s.length(); right++){
            if(map.count(s[right]) == 0 || map[s[right]] < left){
                map[s[right]] = right;
                maxl = max(right - left + 1, maxl);
            }
            else{
                left = map[s[right]]+1;
                map[s[right]] = right;
            }
            
        }

        return maxl;
    }
};
