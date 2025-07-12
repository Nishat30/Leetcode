class Solution {
public:
    bool solve(string s,int idx, int cnt,vector<vector<int>>& dp){
        int n=s.length();
        if(cnt<0) return false;
        if(dp[idx][cnt]!=-1) return dp[idx][cnt];
        if(idx==n){
            return (cnt==0);
        }
        if(s[idx]=='(')return solve(s,idx+1,cnt+1,dp);
        if(s[idx]==')') return solve(s,idx+1,cnt-1,dp);
        return dp[idx][cnt]=solve(s,idx+1,cnt+1,dp)|| solve(s,idx+1,cnt-1,dp) || solve(s,idx+1,cnt,dp);
    }
    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(s,0,0,dp);
    }
    //t.c=N*N
};