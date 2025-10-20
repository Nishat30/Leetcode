class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n<=1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        unsigned long int res=0;
        for(int i=0;i<n;i++){
            res+=solve(i,dp)*solve(n-i-1,dp);
        }
        return dp[n]=res;
    }
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return (int)solve(n, dp);
    }
};