/*
Check if strings are rotations of each other or not


You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.
*/


class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    
    
    bool areRotations(string s1,string s2)
    {
        if(s1.length() != s2.length())
            return false;
        
        string temp = s1+s1;
        int str = temp.find(s2);
        return (str>=0);
    }
};
