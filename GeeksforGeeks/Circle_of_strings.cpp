// User function Template for C++

class Solution {
  public:
    void DFS(int node, vector<int>adj[], vector<bool>&visited)
    {
        visited[node] = 1;
        for(int j = 0; j<adj[node].size();j++)
        {
            if(!visited[adj[node][j]])
            {
                DFS(adj[node][j], adj, visited);
            }
        }
    }
  
    int isCircle(vector<string> &arr) {
        int n = arr.size();
        // edges create karna
        // adjacency list
        // a-z
        // a - 0, b - 1, ..., z - 25
        vector<int>adj[26];
        vector<int>InDeg(26, 0);
        vector<int>OutDeg(26, 0);
        for(int i = 0; i < n;i++)
        {
            string temp = arr[i];
            int u = temp[0] - 'a';
            int v = temp[temp.size()-1]-'a';
            adj[u].push_back(v);
            OutDeg[u]++;
            InDeg[v]++;
        }
        
        // Eulerian Circuit
        // find indegree and outdegree
        for(int i = 0; i < 26;i++)
        {
            if(InDeg[i]!=OutDeg[i])
            {
                return 0;
            }
        }
        
        // All the edges are part of single component
        // all the non zero degree node(InDeg or OutDeg), they should be part of single component
        vector<bool>visited(26, 0);
        int node = arr[0][0]-'a';
        DFS(node, adj, visited);
        
        for(int i = 0; i < 26;i++)
        {
            if(InDeg[i] && !visited[i])
            {
                return 0;
            }
        }
        
        return 1;
    }
};