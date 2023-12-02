/*
387. First Unique Character in a String

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0


*/



class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;

        for(int i = 0; i < s.length(); i++){
            map[s[i]]++;
            // cout<<map[s[i]]<<" "<<s[i]<<endl;
            
        }

        for(int i = 0; i < s.length(); i++){
            if(map[s[i]] == 1)
                return i;
        }

        return -1;
    }
};
