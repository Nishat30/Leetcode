class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        // return (int)solve(0,1,prices,n,dp);
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            //buy
            dp[i][1] = max(-prices[i] + dp[i+1][0] , 0+ dp[i+1][1]);
            //sell
            dp[i][0]= max(prices[i] + dp[i+2][1] , 0+ dp[i+1][0]);            
        }
        return dp[0][1];
    }
};