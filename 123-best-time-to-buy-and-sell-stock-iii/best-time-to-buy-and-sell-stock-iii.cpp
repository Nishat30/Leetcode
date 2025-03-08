class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //tabulation code
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //since we initialize the dp with zero we dont need to consider the base case anymore
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        dp[i][buy][cap] = max(-prices[i]+ dp[i+1][0][cap], 0+ dp[i+1][1][cap]);
                        //ya toh kharida ya phir mtt kharido
                        //same as pick not pick wala case
                    }else{ //sell wala case
                        dp[i][buy][cap]= max(prices[i] + dp[i+1][1][cap-1], 0+ dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};