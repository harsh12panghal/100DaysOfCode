/*
Kth element in Matrix


Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

*/



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  //Your code here
  int min =1, max =10000, mid, pos=0;
  int p = std::min(k, n);
  
  while(min<max)
  {
      mid = (min+max)/2;
      pos=0;
      for(int i=0;i<p;i++)
        pos += upper_bound(mat[i], mat[i] + n, mid) - mat[i];
  
      if(pos<k)
        min = mid+1;
      
      else max = mid;
  }  
  
  return min;
}
