/*
Maximum difference between pair in a matrix



Given an N x N matrix, mat[N][N] of integers. The task is to find the maximum value of mat(c, d) mat(a, b) 
over all choices of indexes such that both c > a and d > b.

*/


int findMaxValue(vector<vector<int>>&mat, int N){
        int maxi = INT_MIN;
         
         int maxArr[N][N];
        // last element of maxArr will be same's as of
        // the input matrix
         maxArr[N-1][N-1] = mat[N-1][N-1];
         
         //finding the max in the last row and putting all those values in maxArr
         int maxv = mat[N-1][N-1];
         for(int j = N-2; j >= 0; j--){
             if(mat[N-1][j] > maxv)
                maxv = mat[N-1][j];
            maxArr[N-1][j] = maxv;
         }
         
         //finding the max in the last col and putting all those values in maxArr
         maxv = mat[N-1][N-1];
         for(int i = N-2; i >= 0; i--){
             if(mat[i][N-1] > maxv)
                maxv = mat[i][N-1];
            maxArr[i][N-1] = maxv;
         }
         
         //we will loop through the last element 
         for(int i = N-2; i>=0; i--){
             for(int j = N-2; j>=0; j--){
                // Update maxValue
                if(maxArr[i+1][j+1] - mat[i][j] > maxi)
                    maxi = maxArr[i+1][j+1] - mat[i][j];
                
                // set maxArr (i, j) 
                maxArr[i][j] = max(mat[i][j], max(maxArr[i+1][j], maxArr[i][j+1]));
             }
         }
         
         return maxi;
    }
