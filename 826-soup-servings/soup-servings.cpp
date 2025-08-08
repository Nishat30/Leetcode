class Solution {
public:
    vector<vector<int>> operations = {
        {100, 0},
        {75, 25},
        {50, 50},
        {25, 75}
    };
    double soupServings(int n) {
        if(n>5000) return 1.0;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1.0));
        return solve(n,n,dp);
    }
    double solve(int a,int b,vector<vector<double>>& dp){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1.0;
        if(b<=0) return 0.0; //insaaf needed!

        if(dp[a][b]!=-1) return dp[a][b];
        double prob=0.0;
        for(auto i:operations){
            int lefta = max(0, a - i[0]);
            int leftb = max(0, b - i[1]);
            prob+=solve(lefta,leftb,dp);
        }
        return dp[a][b]=0.25*prob;
    }
};