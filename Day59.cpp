/*
32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses 
substring
.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".




*/




class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack <int>st;
        st.push(-1);
        int len_max = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            
            else{
                st.pop();
                if(st.empty()){
                  st.push(i);
                }
                else {
                    int len = i-st.top();
                 len_max = max(len,len_max);
                   
                }
            }
            
        }
        return len_max;
    }
};
