class Solution {
public:
    int solve(int idx,vector<int>& arr, int k,int n,vector<int>& dp){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int maxi=INT_MIN;
        int max_sum=INT_MIN,len=0;
        for(int j=idx;j<min(n,idx+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            max_sum=max(max_sum,len*maxi+ solve(j+1,arr,k,n,dp));
        }
        return dp[idx]=max_sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,k,n,dp);
    }
};