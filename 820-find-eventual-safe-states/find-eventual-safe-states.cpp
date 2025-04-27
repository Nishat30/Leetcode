class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int u=graph[i][j];
                adj[u].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adj[node]){
                if(--indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};