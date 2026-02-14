//Position this line where user code will be pasted.
class Solution {
  public:
    void Topological(int node, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&s)
    {
        visited[node] = 1;
        // look at its all neighbour
        for(int j = 0; j < adj[node].size();j++)
        {
            if(!visited[adj[node][j]])
            {
                Topological(adj[node][j], adj, visited, s);
            }
        }
        
        s.push(node);
    }
    
    void DFS(int node, vector<vector<int>>&adj, vector<bool>&visited)
    {
        visited[node] = 1;
        for(int j = 0; j < adj[node].size();j++)
        {
            if(!visited[adj[node][j]])
            {
                DFS(adj[node][j], adj, visited);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        
        // Step 1: Topological sort using DFS
        stack<int>s;
        vector<bool>visited(V, 0);
        for(int i = 0; i < V;i++)
        {
            if(!visited[i])
            {
                Topological(i, adj, visited, s);
            }
        }
        
        // Step 2: Reverse the edges
        vector<vector<int>>adj2(V);
        for(int i = 0; i < V;i++)
        {
            for(int j = 0; j < adj[i].size();j++)
            {
                int u = i;
                int v = adj[i][j];
                adj2[v].push_back(u);
            }
        }
        
        // Step 3: Pop the element from the stack
        // if the popped node is not visited yet
        // SCC++
        // dfs apply karo
        for(int i = 0; i < V;i++)
        {
            visited[i] = 0;
        }
        
        int SCC = 0;
        while(!s.empty())
        {
            int node = s.top();
            s.pop();
            if(!visited[node])
            {
                SCC++;
                DFS(node, adj2, visited);
            }
        }
        
        return SCC;
    }
};