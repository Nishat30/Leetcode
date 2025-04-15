class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto i:edges){
            dist[i[0]][i[1]]=i[2];
            dist[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i++) dist[i][i]=0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==INT_MAX|| dist[k][j]==INT_MAX) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        int cntCity=n;
        int ans=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=cntCity){
                cntCity=cnt;
                ans=i;
            }
        }
        return ans;
    }
};