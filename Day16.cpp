/*
1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

*/

class Solution {
public:
    int minPartitions(string n) {
        int maxi = -1;
        for(char ch: n){
            int num = ch - '0';
            maxi = max(maxi, num);
        }
        return maxi;
    }
};
