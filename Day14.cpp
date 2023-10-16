/*
567. Permutation in String

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

*/


class Solution {
public:

    bool isSame(int arr1[26], int arr2[26]){
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]){
                return false;
            }

        }
        return true;
    }



    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {0};

        for(int i = 0; i < s1.length(); i++){
            int num = s1[i] - 'a';
            arr1[num]++;
        }

        int i = 0;
        int windowLength = s1.length();
        int arr2[26] = {0};
        while(i < windowLength && i < s2.length()){
            int index = s2[i] - 'a';
            arr2[index]++;
            i++;
        }

        if(isSame(arr1, arr2)){
            return true;
        }

        while(i < s2.length()){
            char newChar = s2[i];
            int index = newChar - 'a';
            arr2[index]++;

            char oldChar = s2[i-windowLength];
            index = oldChar - 'a';
            arr2[index]--;

            i++;

            if(isSame(arr1, arr2))
                return true;
        }

        return false;
    }
};
