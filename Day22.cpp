/*
1572. Matrix Diagonal Sum

Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the 
elements on the secondary diagonal that are not part of the primary diagonal.


*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();

        int row = 0;
        int col = n-1;
        int sum = 0;

        for(int j = 0; j < n; j++){
            sum += mat[row][j];
            row++;
        }

        for(int i = 0; i < n; i++){
            if(col == i){
                col--;
                continue;
            }
            else{
                sum += mat[i][col];
                col--;
            }
        }

        return sum;
    }
};
