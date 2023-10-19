/*
54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.


*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row*col;

        int startingRow = 0;
        int endingRow = row - 1;
        int startingCol = 0;
        int endingCol = col - 1;

        while(count<total){
            
            // Printing Starting Row
            for(int index = startingCol; count<total && index <= endingCol; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            // Printing ending col
            for(int index = startingRow; count<total && index <= endingRow; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            // Printing ending Row
            for(int index = endingCol; count<total && index >= startingCol; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            // Printing starting col
            for(int index = endingRow; count<total && index >= startingRow; index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
    return ans;
        
    }
};
