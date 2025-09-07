class Solution {
public:
    int f(int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=f(i-1,j,dp);
        int left=f(i,j-1,dp);
        return dp[i][j]=up+left;
    }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,dp);
        vector<int> dp(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=1;
                }else{
                    int up=0,left=0;
                    if(i>0) up=dp[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=up+left;
                }
            }
            dp=temp;
        }
        return dp[n-1];
    }
};