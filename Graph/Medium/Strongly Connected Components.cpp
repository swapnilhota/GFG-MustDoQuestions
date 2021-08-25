/*
Kosaraju's Algo

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 

Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.
 

Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).
 

Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
Sum of E over all testcases will not exceed 25*106
*/

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> stk;
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                dfs(adj, i, stk, visited);
            }
        }
        
        vector<int> trans[V];
        
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                trans[adj[i][j]].push_back(i);
            }
        }
        
        for(int i=0; i<V; i++) visited[i]=false;
        
        int cnt=0;
        
        while(!stk.empty())
        {
            int node = stk.top(); stk.pop();
            if(visited[node]) continue;
            dfs2(trans, node, visited);
            cnt++;
        }
        
        return cnt;
    }
    
    void dfs2(vector<int>* trans, int curr, vector<bool> &visited)
    {
        if(visited[curr]) return;
        visited[curr]=true;
        for(int i=0; i<trans[curr].size(); i++)
        {
            dfs2(trans, trans[curr][i], visited);
        }
    }
    
    void dfs(vector<int>* adj, int curr, stack<int> &stk, vector<bool> &visited)
    {
        if(visited[curr])
        {
            return;
        }
        visited[curr] = true;
        
        for(int i=0; i<adj[curr].size(); i++)
        {
            if(visited[adj[curr][i]]) continue;
            dfs(adj, adj[curr][i], stk, visited);
        }
        
        stk.push(curr);
    }
};
