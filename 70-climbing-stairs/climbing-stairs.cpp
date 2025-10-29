class Solution {
public:
    void solve(int i,int &cnt,vector<int>& dp){
        if (i <= 0) {     
            cnt++;
            return;
        }
        if (dp[i] != -1) {   // already computed number of ways from i
            cnt += dp[i];
            return;
        }

        int before = cnt; 
        if(i-2>=0) solve(i - 2, cnt, dp);
        if(i-1>=0) solve(i - 1, cnt, dp);
        dp[i] = cnt - before; 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int cnt=0;
        solve(n,cnt,dp);
        return cnt;
    }
};