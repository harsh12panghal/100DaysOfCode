/* 
1552. Magnetic Force Between Two Balls

In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. 
Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the 
minimum magnetic force between any two balls is maximum.

Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic 
force is 3. We cannot achieve a larger minimum magnetic force than 3.

Used the Aggresive cow approach to solve this problem. We know to use this approach when asked to find the "the 
minimum magnetic force between any two balls is maximum."

*/


class Solution {
public:

    bool isPossible(vector<int>& position, int m, int mid){
        int ballcnt = 1;
        int lasPos = position[0];

        for(int i = 0; i < position.size(); i++){
            if(position[i] - lasPos >= mid){
                ballcnt++;
                if(ballcnt == m){
                    return true;
                }
                lasPos = position[i];
            }
            
        }
        return false;
    }


    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size()-1;
        int s = 0;
        int e = position[n] - position[0];
        int mid = s + (e-s)/2;
        int ans = -1;

        while(s<=e){
            if(isPossible(position, m, mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
    
    return ans;
    }
};
