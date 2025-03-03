class Solution {
public:
    bool solve(int i,vector<int>& nums,int target,vector<vector<int>> dp){
        if(target==0){return true;}
        if (i == 0) return nums[i] == target; 
        if(dp[i][target]!=-1)return dp[i][target];
        bool not_take=solve(i-1,nums,target,dp);
        bool take=false;
        if(target>=nums[i]){
            take=solve(i-1,nums,target-nums[i],dp);}
        return dp[i][target]=take or not_take; 
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;
        for(int num:nums){
            total_sum+=num;
        }
        int target=total_sum/2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        if(total_sum%2!=0){
            return false;
        }else{
            // return solve(n-1,nums,target,dp);
            for(int i=0;i<n;i++){
               dp[i][0]=true; //if target is zero it can be achieved kahi se bhi
            }
            // Initialize the first row based on the first element of the array
            if (nums[0] <= target){
               dp[0][nums[0]] =true;
            }
            // Fill in the DP table using a bottom-up approach
            for (int ind = 1; ind < n; ind++) {
                for (int k = 1; k <= target; k++) {
                // Exclude the current element
                    bool notTaken = dp[ind - 1][k];

                // Include the current element if it doesn't exceed the target
                    bool taken = false;
                    if (nums[ind] <= k)
                       taken = dp[ind - 1][k - nums[ind]];

                // Update the DP table
                    dp[ind][k] = notTaken || taken;
            }
        }
        }
        return dp[n-1][target];
    }
};