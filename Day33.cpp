
/*
38. Count and Say

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly
one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

For example, the saying and conversion for digit string "3322251":


*/

class Solution {
public:
    string countAndSay(int n) {
        string ans = "";
        if(n == 1){
            return "1";
        }
        else{
            string lastDig = countAndSay(n-1);

            char currentDig = lastDig[0];
            int cnt = 1;

            string temp = "";

            for(int i = 1; i < lastDig.size(); i++){
                if(lastDig[i] != currentDig){
                    temp += to_string(cnt) + currentDig;
                    cnt = 1;
                    currentDig = lastDig[i];
                }
                else{
                    cnt++;
                }
                
            }
            temp += to_string(cnt) + currentDig;
            return temp;
        }
        
    }
};
