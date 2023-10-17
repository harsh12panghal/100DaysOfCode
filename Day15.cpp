/*
125. Valid Palindrome

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric 
characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

*/


class Solution {
public:

    char lowercase(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            return ch;
        else if(ch >= 'A' && ch <= 'Z'){
            char temp = ch - 'A' + 'a';
            return temp;
        }
        else{
            return '\0';
        }
    }


    bool isPalindrome(string s) {
        int st = 0;
        int e = s.size()-1;

        while(st <= e){
            char start = lowercase(s[st]);
            char end = lowercase(s[e]);

            if(start == '\0'){
                st++;
            }
            else if(end == '\0'){
                e--;
            }
            else if(start != end){
                return false;
            }
            else{
                st++;
                e--;
            }
        }
        return true;
    }
};
