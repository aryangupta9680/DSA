class Solution {
  public:
    bool find(int node, vector<vector<int>> &adj, int v, int m, vector<int>&color)
    {
        // base case 
        if(node == v)
        {
            return 1;
        }
        
        // color the node with m color
        for(int i = 0; i < m;i++)
        {   
            bool IsPossible = 1;
            // check if adjacent node doesn't have same color 
            for(int j = 0; j < v;j++)
            {
                if(adj[node][j] && color[j] == i)
                {
                    IsPossible = 0;
                    break;
                }
            }
            
            if(IsPossible)
            {
                color[node] = i;
                if(find(node + 1, adj, v, m, color))
                {
                    return 1;
                }
                
                color[node] = -1;
            }
        }
        
        return 0;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int>color(v, -1);
        vector<vector<int>> adj(v, vector<int>(v, 0));

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int w = edges[i][1];
        
            adj[u][w] = 1;
            adj[w][u] = 1;  
        }
        return find(0, adj, v, m, color);
    }
};