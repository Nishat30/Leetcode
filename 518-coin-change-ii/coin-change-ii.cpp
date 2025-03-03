class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) dp[0][t] = 1;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                unsigned long long not_take=dp[i-1][target];
                unsigned long long take=0;
                if (target >= coins[i]) { // Ensure valid index
                    take =dp[i][target - coins[i]];
                }
                dp[i][target]=take+not_take;
            }
        }
        return (int)dp[n-1][amount];
    }
};