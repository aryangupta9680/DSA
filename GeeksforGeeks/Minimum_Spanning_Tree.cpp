class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
        
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // priority queue
        // weight, node, parent
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>> >, greater<pair<int, pair<int, int>>>>pq;
        vector<bool>IsMST(V, 0);
        vector<int>parent(V);
        
        int cost = 0;
        pq.push({0, {0, -1}});
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();
            
            if(!IsMST[node])
            {
                IsMST[node] = 1;
                cost += wt;
                parent[node] = par;
                
                for(int j = 0; j < adj[node].size();j++)
                {
                    int nextNode = adj[node][j].first;
                    int nextWt   = adj[node][j].second;
                    
                    if(!IsMST[nextNode])
                    {
                        pq.push({nextWt, {nextNode, node}});
                    }
                }
            }
        }
        
        return cost;
    }
};