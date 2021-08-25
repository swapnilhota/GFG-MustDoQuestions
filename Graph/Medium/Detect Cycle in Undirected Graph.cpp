/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Example 1:

Input:   

Output: 1
Explanation: 1->2->3->4->1 is a cycle.
Example 2:

Input: 

Output: 0
Explanation: No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
 

Constraints:
1 ≤ V, E ≤ 105
*/

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    vector<bool> visited(V, false);
	    for(int i=0; i<V; i++)
	    {
	        if(!visited[i])
	        {
	            if(solve(adj, -1, i, visited)) return true;
	        }
	    }
	    return false;
	}
	
	bool solve(vector<int>* adj, int src, int curr, vector<bool> &visited)
	{
	    visited[curr]=true;
	    
	    for(int i=0; i<adj[curr].size(); i++)
	    {
	        if(!visited[adj[curr][i]])
	        {
	            if(solve(adj, curr, adj[curr][i], visited)) return true;
	        }
	        else
	        {
	            if(adj[curr][i]!=src)
	            {
	                return true;
	            }
	        }
	    }
	    
	    return false;
	}
};
