class Solution {
public:
    int solve(int idx1,int idx2,string text1, string text2,vector<vector<int>>& dp){
        //base case
        if((idx1<0) || (idx2<0)){
            return 0;
        }
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        //match wala case
        if(text1[idx1]==text2[idx2]){
            return dp[idx1][idx2]=1+solve(idx1-1,idx2-1,text1,text2,dp);
        }
        //not match wala case
        return dp[idx1][idx2]=0 + max(solve(idx1-1,idx2,text1,text2,dp),solve(idx1,idx2-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1)); 
        //memorization code
        // return solve(n-1,m-1,text1,text2,dp);
        //tabulation k waqt hai ab dosto

        //step 1:- base case
        //to make it simplier we will shift base case from idx1<0 to idx1==0
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for (int j=0;j<m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
                }else{
                dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);}
            }
        } 
        return dp[n][m];
    }
};