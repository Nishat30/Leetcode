class Solution {
public:
    long solve(int i,int buy,vector<int>& prices,int n,vector<vector<vector<int>>>& dp,int cap){
        if(cap==0) return 0;
        if(i==n){return 0;} //kuch nhi bacha aur profit k lie
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        long profit=0;
        if(buy){
            profit = max(-prices[i]+ solve(i+1,0,prices,n,dp,cap), 0+ solve(i+1,1,prices,n,dp,cap));
            //ya toh kharida ya phir mtt kharido
            //same as pick not pick wala case
        }else{ //sell wala case
            profit= max(prices[i] + solve(i+1,1,prices,n,dp,cap-1), 0+ solve(i+1,0,prices,n,dp,cap));
        }
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int cap=2;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return (int)solve(0,1,prices,n,dp,cap);
    }
};