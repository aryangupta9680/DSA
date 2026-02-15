// User function template for C++

class Solution {
  public:
    // Function to return a list of lists of integers denoting the members
    // of strongly connected components in the given graph.
    
    void DFS(int node, vector<int>adj[], vector<bool>&visited, vector<int>&disc, vector<int>&low, stack<int>&s, vector<bool>&InStack, vector<vector<int>>&ans, int &timer)
    {
        visited[node] = 1;
        disc[node] = low[node] = timer;
        s.push(node);
        InStack[node] = 1;
        
        for(int j = 0; j < adj[node].size();j++)
        {
            int neighbour = adj[node][j];
            if(!visited[neighbour])
            {
                timer++;
                DFS(neighbour, adj, visited, disc, low, s, InStack, ans, timer);
                low[node] = min(low[node], low[neighbour]);
            }
            else
            {
                // if it is present in stack or not
                if(InStack[neighbour])
                {
                    low[node] = min(low[node], disc[neighbour]);
                }
            }
        }
        
        if(disc[node] == low[node])
        {
            vector<int>temp;
            while(!s.empty() && s.top()!=node)
            {
                temp.push_back(s.top());
                InStack[s.top()] = 0;
                s.pop();
            }
            
            temp.push_back(node);
            InStack[node] = 0;
            s.pop();
            sort(temp.begin(), temp.end());
            
            ans.push_back(temp);
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        vector<vector<int>>ans;
        vector<int>disc(V);
        vector<int>low(V);
        vector<bool>visited(V, 0);
        stack<int>s;
        vector<bool>InStack(V, 0);
        int timer = 0;
        
        for(int i = 0;i < V;i++)
        {
            if(!visited[i])
            {
                DFS(i, adj, visited, disc, low, s, InStack, ans, timer);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};