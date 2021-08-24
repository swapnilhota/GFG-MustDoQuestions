/*
Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

 


Example 1:

Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1}, 
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
unit time. And, during 2nd unit time, patient at 
{1, 0} will get infected and will infect patient 
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.
Example 2:

Input:
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
Output:
-1
Explanation:
All patients will not be infected.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function helpaterp() which takes a 2-D Matrix hospital as input parameter and returns the minimum units of time in which all patients will be infected or -1 if it is impossible.

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(R*C)


Constraints:
1 ≤ R,C ≤ 1000
0 ≤ mat[i][j] ≤ 2
*/

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int m = hospital.size();
        int n = hospital[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        int uninfected_cnt=0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(hospital[i][j]==2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j]=true;
                }
                else if(hospital[i][j]==1)
                {
                    uninfected_cnt++;
                }
            }
        }
        
        
        
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        
        int t=0;
        
        while(!q.empty())
        {
            auto current = q.front(); q.pop();
            int r = current.first.first;
            int c = current.first.second;
            t = current.second;
            
            for(auto d: dir)
            {
                int i = r+d.first;
                int j = c+d.second;
                
                if(i>=m || j>=n || i<0 || j<0 || visited[i][j]==true || hospital[i][j]!=1)
                {
                    continue;
                }
                
                q.push({{i, j}, t+1});
                uninfected_cnt--;
                visited[i][j]=true;
            }
        }
        
        if(uninfected_cnt!=0)
        {
            return -1;
        }
        
        return t;
    }
};
