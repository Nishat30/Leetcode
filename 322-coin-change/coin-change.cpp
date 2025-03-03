class Solution {
public:
    int solve(int i,vector<int>& a, int target,vector<vector<int>>& dp){
        if(i==0){
            if(target%a[i]==0)return target/a[i];
            else return 1e9;
        }
        if(dp[i][target]!=-1)return dp[i][target];
        int not_take= 0+ solve(i-1,a,target,dp);
        int take=1e9;//jab minimun chahie ho toh max se initialize krdo 
        if(a[i]<=target){
            int t= solve(i,a,target-a[i],dp);//jab infinite case ho toh we stand at that index only
            if (t != 1e9) { // Ensure valid result before adding 1
                take = 1 + t;
            }
        }
        return dp[i][target]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int result = solve(n - 1, coins, amount, dp);
        return (result >= 1e9) ? -1 : result;
    }
};