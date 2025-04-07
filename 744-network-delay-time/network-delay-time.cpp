class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            //directed hai
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //{node,cost}
        pq.push({k,0});
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.first;
            int cost=it.second;
            for(auto nbr:adj[node]){
                int adjNode=nbr.first;
                int adj_cost=nbr.second;

                if((cost+adj_cost) < dist[adjNode]){
                    dist[adjNode]=cost+adj_cost;
                    pq.push({adjNode,cost+adj_cost});
                }
            }
        }
        int min_time=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            min_time=max(min_time,dist[i]);
        }
        return min_time;
    }
};