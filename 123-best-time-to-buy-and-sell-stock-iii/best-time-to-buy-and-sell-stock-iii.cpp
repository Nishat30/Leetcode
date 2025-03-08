class Solution {
public:
//trans=0,1,2,3
//where 0 and 2 implie buy & 1 and 3 implies sell
    long solve(int idx, int trans,vector<int>& prices,int n,vector<vector<int>>& dp){
        if(trans==4){return 0;}
        if(idx==n){return 0;}
        if(dp[idx][trans]!=-1){return dp[idx][trans];}
        long profit=0;
        if(trans%2==0){ //buy wala case
           profit=max(-prices[idx]+solve(idx+1,trans+1,prices,n,dp), 0+solve(idx+1,trans,prices,n,dp));
        }else{//sell wala case
           profit=max(prices[idx]+solve(idx+1,trans+1,prices,n,dp), 0+solve(idx+1,trans,prices,n,dp));
        }
        return dp[idx][trans]=profit;
    }
    int maxProfit(vector<int>& prices) {
        //tabulation code
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(5,-1));
        return solve(0,0,prices,n,dp);
    }
};