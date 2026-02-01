// First Method: // Using Prim's Algorithm
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







// Second Method: Using Kruskal's Algorithm
class Solution {
  public:
    int FindParent(int u, vector<int>&parent)
    {
        if(u==parent[u])
        {
            return u;
        }
        
        return parent[u] = FindParent(parent[u], parent); 
        // path compression
    }
    
    void UnionByRank(int u, int v, vector<int>&parent, vector<int>&rank)
    {
        int pu = FindParent(u, parent);
        int pv = FindParent(v, parent);
        
        if(rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if(rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
        
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int>parent(V); // ultimate parent will help us to determine set
        vector<int>rank(V, 0); // it will help us to merge set
        
        for(int i = 0; i < V;i++)
        {
            parent[i] = i;
        }
        
        vector<pair<int, pair<int, int>>>temp;
        for(int i = 0; i < V;i++)
        {
            for(int j = 0; j < adj[i].size();j++)
            {
                temp.push_back({adj[i][j].second, {i, adj[i][j].first}});
            }
        }
        
        // priority queue
        // weight, u, v
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>> >, greater<pair<int, pair<int, int>>>> pq(temp.begin(), temp.end());
        
        int cost = 0;
        int edge = 0;
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            // check if they are in different set
            if(FindParent(u, parent) != FindParent(v, parent))
            {
                cost += wt;
                UnionByRank(u, v, parent, rank);
                edge++;
            }
            
            if(edge==V-1)
            {
                break;
            }
        }
        
        return cost;
    }
};