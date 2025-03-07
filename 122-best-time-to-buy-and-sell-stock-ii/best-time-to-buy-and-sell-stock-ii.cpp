class Solution {
public:
    long solve(int i,int buy,vector<int>& prices,int n,vector<vector<int>>& dp){
        if(i==n){return 0;} //kuch nhi bacha aur profit k lie
        if(dp[i][buy]!=-1)return dp[i][buy];
        long profit=0;
        if(buy){
            profit = max(-prices[i]+ solve(i+1,0,prices,n,dp), 0+ solve(i+1,1,prices,n,dp));
            //ya toh kharida ya phir mtt kharido
            //same as pick not pick wala case
        }else{ //sell wala case
            profit= max(prices[i] + solve(i+1,1,prices,n,dp), 0+ solve(i+1,0,prices,n,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        // // return (int)solve(0,1,prices,n,dp);
        // dp[n][0]=0;
        // dp[n][1]=0;
        // for(int i=n-1;i>=0;i--){
        //     for(int buy=0;buy<2;buy++){
        //         long profit=0;
        //         if(buy){
        //             profit = max(-prices[i] + dp[i+1][0] , 0+ dp[i+1][1]);
        //         }else{ 
        //             profit= max(prices[i] + dp[i+1][1] , 0+ dp[i+1][0]);
        //         }
        //         dp[i][buy]=profit;
        //     }
        // }
        // return dp[0][1];

        //space optmization
        vector<int> prev(2,0),cur(2,0);
        prev[0]=0;
        prev[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                long profit=0;
                if(buy){
                    profit = max(-prices[i] + prev[0] , 0+ prev[1]);
                }else{ 
                    profit= max(prices[i] + prev[1] , 0+ prev[0]);
                }
                cur[buy]=profit;
            }
            prev=cur;
        }
        return prev[1];
    }
};