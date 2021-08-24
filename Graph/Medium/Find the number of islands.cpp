/*
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
 

Example 1:

Input:
grid = {{0,1},{1,0},{1,1},{1,0}}
Output:
1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.
Example 2:

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function numIslands() which takes grid as input parameter and returns the total number of islands.
 

Expected Time Compelxity: O(n*m)
Expected Space Compelxity: O(n*m)
 

Constraints:
1 ≤ n, m ≤ 500
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int ans=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    if(!visited[i][j])
                    {
                        helper(grid, i, j, visited);
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
    
    void helper(vector<vector<char>>& grid, int r, int c, vector<vector<bool>> &visited)
    {
        if(r>=grid.size() || c>=grid[0].size() || r<0 || c<0)
        {
            return;
        }
        if(visited[r][c])
        {
            return;
        }
        if(grid[r][c]=='0')
        {
            return;
        }
        
        visited[r][c]=true;
        
        //N
        helper(grid, r-1, c, visited);
        //NW
        helper(grid, r-1, c-1, visited);
        //W
        helper(grid, r, c-1, visited);
        //SW
        helper(grid, r+1, c-1, visited);
        //S
        helper(grid, r+1, c, visited);
        //SE
        helper(grid, r+1, c+1, visited);
        //E
        helper(grid, r, c+1, visited);
        //NE
        helper(grid, r-1, c+1, visited);
    }
};
