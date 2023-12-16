


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        // int n = s.length();
        // char str[n];
        // for(int i = 0; i < n; i++){
        //     str[i] = s[i];
        // }
        

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t)
            return true;
        else
            return false;
    
    }
};
