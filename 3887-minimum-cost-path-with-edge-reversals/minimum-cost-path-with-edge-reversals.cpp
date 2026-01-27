class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> outgoing(n),incoming(n);
        for(auto &i:edges){
            //directed graph wala logic
            outgoing[i[0]].push_back({i[1],i[2]});
            incoming[i[1]].push_back({i[0],i[2]});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,INT_MAX);
        dist[0]=0;
        pq.push({0,0});
        //NORMAL BFS
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            long long cost=it.first;int node=it.second;
            if(cost!=dist[node])continue;
            //NORMAL ONE WITHOUT FLIP
            for(auto nbr:outgoing[node]){
                long long nd=cost+nbr.second;
                if(nd<dist[nbr.first]){
                    dist[nbr.first]=nd;
                    pq.push({nd,nbr.first});
                }
            }
            //FLIPPED ONE
            for(auto nbr:incoming[node]){
                long long nd=cost+2LL*nbr.second;
                if(nd<dist[nbr.first]){
                    dist[nbr.first]=nd;
                    pq.push({nd,nbr.first});
                }
            }
        }

        return dist[n-1]>=INT_MAX?-1:(int)dist[n-1];
    }
};
