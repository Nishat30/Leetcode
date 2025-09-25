class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>& dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int down=triangle[i][j]+solve(i+1,j,triangle,n,dp);
        int dg=triangle[i][j]+solve(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(down,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solve(0,0,triangle,n,dp);
        //tabulation
        // for(int i=n-1;i>=0;i--){
        //     dp[n-1][i]=triangle[n-1][i];
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int up=triangle[i][j]+dp[i+1][j];
        //         int dg=triangle[i][j]+dp[i+1][j+1];
        //         dp[i][j]=min(up,dg);
        //     }
        // }
        // return dp[0][0];
        //space optimization
        vector<int> front(n,0);
        vector<int> curr(n,0);
        for(int i=n-1;i>=0;i--){
            front[i]=triangle[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int up=triangle[i][j]+front[j];
                int dg=triangle[i][j]+front[j+1];
                curr[j]=min(up,dg);
            }
            front=curr;
        }
        return front[0];
    }
};