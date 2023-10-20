/*
59. Spiral Matrix II


Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.


*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> ans(n, vector<int> (n, 0));

        int index = 1;
        int total = n*n;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = n-1;
        int endingCol = n-1;


        while(index <= total){
            for(int i = startingCol; index <= total && i <= endingCol; i++){
                ans[startingRow][i] = index++;        
            }
            startingRow++;

            for(int i = startingRow;index <= total && i <= endingRow; i++){
                ans[i][endingCol] = index++;;
            }
            endingCol--;

            for(int i = endingCol; index <= total && i >= startingCol; i--){
                ans[endingRow][i] = index++;;
            }
            endingRow--;

            for(int i = endingRow;index <= total && i >= startingRow; i--){
                ans[i][startingCol] = index++;;
            }
            startingCol++;

        }
        return ans;
       
    }
};
