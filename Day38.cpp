/*
2396. Strictly Palindromic Number


An integer n is strictly palindromic if, for every base b between 2 and n - 2 
(inclusive), the string representation of the integer n in base b is palindromic.

Given an integer n, return true if n is strictly palindromic and false otherwise.

A string is palindromic if it reads the same forward and backward.

*/



class Solution {
public:
    long long int baseCase(int a, int b){
        if(a == 0){
            return 0;
        }
        else{
            return (a%b + 10 * baseCase(a/2, b));
        }
    }

    bool checkPalindrome(string arr, int i, int j){
        if(i > j){
            return true;
        }
        if(arr[i] != arr[j])
            return false;
        else{
            checkPalindrome(arr, i++, j--);
        }
        return -1;
    }

    bool isStrictlyPalindromic(int n) {
        
        for(int i = 2; i <= n-2; i++){
            long long int binary = baseCase(n, i);
            string binaryStr = to_string(binary);
            int s = 0;
            int e = binaryStr.length();
            if(checkPalindrome(binaryStr, s, e))
                return true;
            else{
                return false;
            }
        }

        return -1;
    }
};
