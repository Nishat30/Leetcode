class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& a,int m,vector<vector<int>>& dp){
        if(j<0 || j>=m) return 1e9;
        if(i==0)return a[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int s=a[i][j] + solve(i-1,j,a,m,dp);
        int ld=a[i][j] + solve(i-1,j-1,a,m,dp);
        int rd=a[i][j] + solve(i-1,j+1,a,m,dp);
        return dp[i][j]= min(s,min(ld,rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int mini = INT_MAX;
        for(int j=0;j<m;j++){
            dp[0][j]= matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
            int up = matrix[i][j] + dp[i - 1][j];
            int leftDiagonal = matrix[i][j];
            if (j - 1 >= 0) {
                leftDiagonal += dp[i - 1][j - 1];
            } else {
                leftDiagonal += 1e9; 
            }
            int rightDiagonal = matrix[i][j];
            if (j + 1 < m) {
                rightDiagonal += dp[i - 1][j + 1];
            } else {
                rightDiagonal += 1e9; 
            }
            dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
        }
    }
    int maxi = INT_MAX;
    for (int j = 0; j < m; j++) {
        mini = min(mini, dp[n - 1][j]);
    }
    return mini;
    }
};