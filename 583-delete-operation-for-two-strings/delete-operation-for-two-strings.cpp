class Solution {
public:
    int LCS(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
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
    int minDistance(string word1, string word2) {
        //first we will find the longes common subsequence in word1 and word2 then we will delete the word1len-len(lcs) and insert word2len-len(lcs) 

        int n=word1.length();
        int m=word2.length();
        int len=LCS(word1,word2);
        int del=n-len;
        int ins=m-len;
        return del+ins;
    }
};