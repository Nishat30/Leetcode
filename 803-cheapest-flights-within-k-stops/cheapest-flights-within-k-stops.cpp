class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //we dont need a priority queue kyuki we dont need min dist we need min distance at k stops
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            //directed hai
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q; //{stops,node,cost}
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k) continue;
            for(auto nbr:adj[node]){
                int adjNode=nbr.first;
                int adj_cost=nbr.second;

                if(((cost+adj_cost) < dist[adjNode]) && stop<=k){
                    dist[adjNode]=cost+adj_cost;
                    q.push({stop+1,{adjNode,cost+adj_cost}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};