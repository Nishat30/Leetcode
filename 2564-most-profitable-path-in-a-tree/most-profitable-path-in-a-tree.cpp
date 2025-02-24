class Solution {
public:
    /*dfs for bob aur bfs for alice
    T.C- Bob_dfs=O(N)
         Alice_bfs=O(N)
         overall~O(N)
    S.C- recursion stack=O(N)
         visited_array=O(N)
         queue=O(N)
         overall~O(N)*/

        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> bobMap;
        int aliceIncome;
        bool DFSBob(int curr,int tm, vector<bool>&visited){
            visited[curr]=true;
            bobMap[curr]=tm;
            if(curr==0) return true; //bob pohuch gye
            for(auto &i:adj[curr]){
                if(!visited[i]){
                    if(DFSBob(i,tm+1,visited)==true){
                        return true;
                    }
                }
            }
            bobMap.erase(curr);
            return false;
            
        }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size();

        aliceIncome=INT_MIN;
        for(vector<int>& i:edges){
            int u=i[0];
            int v=i[1];
            //undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int time=0;
        vector<bool>visited(n,false);
        DFSBob(bob,time,visited);

        int income=0;
        visited.assign(n,false);

        //BFS
        queue<vector<int>> q;
        q.push({0,0,0,}); //{node,time,income}

        while(!q.empty()){
            int node=q.front()[0];
            int tm=q.front()[1];
            int inc=q.front()[2];

            q.pop();
            if(bobMap.find(node)==bobMap.end() || bobMap[node]>tm){
                //alice phle gate kholi 
                inc+=amount[node];
            }else if(tm==bobMap[node]){
                //dono same time m pohuche
                inc+=amount[node]/2;
            }

            if(adj[node].size()==1 && node!=0){
                //leaf node pohuch gyi
                aliceIncome=max(aliceIncome,inc);
            }

            for(int &i:adj[node]){
                if(!visited[i]){
                    q.push({i,tm+1,inc});
                }
            }
            visited[node]=true;
        }
        return aliceIncome;
    }
};