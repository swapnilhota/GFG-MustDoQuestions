/*
Given a N x N matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Example 1:
Input:
N = 4
mat[][] =     {{16, 28, 60, 64},
                   {22, 41, 63, 91},
                   {27, 50, 87, 93},
                   {36, 78, 87, 94 }}
K = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
 

Example 2:
Input:
N = 4
mat[][] =     {{10, 20, 30, 40}
                   {15, 25, 35, 45}
                   {24, 29, 37, 48}
                   {32, 33, 39, 50}}
K = 7
Output: 30
Explanation: 30 is the 7th smallest element.


Your Task:
You don't need to read input or print anything. Complete the function kthsmallest() which takes the mat, N and K as input parameters and returns the kth smallest element in the matrix.
 

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 50
1 <= mat[][] <= 10000
1 <= K <= N*N
*/

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int start = mat[0][0];
  int end = mat[n-1][n-1];
  
  while(start<=end)
  {
      int mid = start + (end-start)/2;
      
      int cnt=0;
      
      for(int i=0; i<n; i++)
      {
          cnt += upper_bound(mat[i], mat[i]+n, mid) - mat[i];
      }
      
      if(cnt<k)
      {
          start=mid+1;
      }
      else
      {
          end=mid-1;
      }
  }
  
  return start;
}
