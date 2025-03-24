#define ll long long int
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto i: roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        vector<ll> dist(n,1e18),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            ll dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if (dis > dist[node]) continue;

            for(auto i:adj[node]){
                int adjNode=i.first;
                int edW=i.second;
                //this is the first time i am coming
                //with this short distance
                if(dis+edW< dist[adjNode]){
                    dist[adjNode]=dis+ edW;
                    pq.push({dis+ edW,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dis+edW == dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
