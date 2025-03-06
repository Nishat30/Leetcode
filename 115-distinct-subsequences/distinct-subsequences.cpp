class Solution {
public:
    int solve(int i,int j,string s, string t,vector<vector<int>>& dp){
        if(j==0) return 1 ;//t is exhausted which means we have matched the string
        if(i==0) return 0; //s hii khtam phir toh khela khatam

        if(dp[i][j]!=-1)return dp[i][j];
        //2 cases bnega 
        //1> matched
        if(s[i-1]==t[j-1]){
            return dp[i][j]=(solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp));  //whi lelo phir dusra k lie bhi dekh lo aur add bhi krlo ways ko
        }
        //else wala case jaha match hii nhi hua hai
        return dp[i][j]=solve(i-1,j,s,t,dp);//aage badh jao
    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        //memorization
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1)); //1 based indexing
        return solve(n,m,s,t,dp);
    }
};