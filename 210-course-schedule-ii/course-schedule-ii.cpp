class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0){

        }
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &i:prerequisites){
            adj[i[1]].push_back(i[0]); // this means 0 is dependent on 1
            indegree[i[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
             q.push(i);  
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int next=q.front();
            q.pop();
            ans.push_back(next);
            for(auto& j:adj[next]){
                indegree[j]--;
                if(indegree[j]==0){
                    q.push(j);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};