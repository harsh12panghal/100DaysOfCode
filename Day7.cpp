/*
367. Valid Perfect Square

Given a positive integer num, return true if num is a perfect square or false otherwise.
*/


class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 0;
        int e = num;
        long long mid = s+(e-s)/2;

        

        while(s<=e){
            long long square = mid*mid;
            if(square == num){
                return true;
            }
            else if(square > num){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return false;
    }
};
