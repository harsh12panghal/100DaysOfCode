/*
204. Count Primes


Given an integer n, return the number of prime numbers that are strictly less than n.

*/



class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        prime[0], prime[1] = false;
        int cnt = 0;

        for(int i = 2; i < n; i++){
            if(prime[i]){
                cnt++;
                for(int j = i*2; j < n; j=j+i){
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};
