class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto&i:prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            cnt++;
            for(auto& idx:adj[i]){
                indegree[idx]--;
                if(indegree[idx]==0){
                    q.push(idx);
                }
            }
        }
        if(cnt==numCourses){
            return true;
        }else{
            return false;
        }
    }
};