class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        for(auto i:queries){
            int r1=i[0];
            int r2=i[2];
            int c1=i[1];
            int c2=i[3];
            for (int r = r1; r <= r2; r++) {
                ans[r][c1] += 1;
                if (c2 + 1 < n)
                    ans[r][c2 + 1] -= 1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j-1>=0){
                    ans[i][j]=ans[i][j]+ans[i][j-1];
                }
            }
        }
        return ans;
    }
};