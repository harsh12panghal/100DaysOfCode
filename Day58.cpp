/*
5. Longest Palindromic Substring


Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


*/


class Solution {
public:
    string longestPalindrome(string str) {
        int s = 0;
        int e = 0;
        int maxl = 1;
        string ans = "";

        for(int i = 0; i < str.length(); i++){
            int l = i, r = i;
            while(l >= 0 && r < str.length()){
                if(str[l] != str[r]){
                    break;
                }
                l--;
                r++;
            }
            int len = r-l-1;
            if(len > maxl){ 
                maxl = len;
                s = l+1;
                e = r-1;
            }
        }

        for(int i = 0; i < str.length(); i++){
            int l = i, r = i+1;
            while(l >= 0 && r < str.length()){
                if(str[l] != str[r]){
                    break;
                }
                l--;
                r++;
            }
            int len = r-l-1;
            if(len > maxl){ 
                maxl = len;
                s = l+1;
                e = r-1;
            }
        }

        return ans = str.substr(s, maxl);;
    }
};
