class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            unsigned long int res=0;
            for(int j=0;j<i;j++){
                res+=dp[j]*dp[i-j-1];
            }
            dp[i]=res;
        }
        return dp[n];
    }
};