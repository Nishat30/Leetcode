class Solution {
public:
    int solve(int i, int j, vector<int>& cuts,vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for (int k = i; k <= j; k++) { 
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int> (m,0));
        // return solve(1, cuts.size()-2, cuts,dp);
        for(int i=m-1;i>0;i--){
            for(int j=i;j<m-1;j++){
                int mini = 1e9;
                for (int k = i; k <= j; k++) { 
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j] ;
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        } 
        return dp[1][cuts.size()-2];
        // cuts.insert(cuts.begin(),0);
		// cuts.insert(cuts.end(),n);
		// sort(cuts.begin(),cuts.end());
		// int m=cuts.size();
		// vector<vector<int>> dp(m,vector<int>(m,0));
		// for(int i=m-1;i>=1;i--){
		// 	for(int j=i;j<=m-2;j++){
		// 		int mini=1e9;
		// 		for(int ind=i;ind<=j;ind++){
		// 			int cost= cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
		// 			mini=min(mini,cost);
		// 		}
		// 		dp[i][j]=mini;
		// 	}
		// }
		// return dp[1][cuts.size()-2];
    }
};
