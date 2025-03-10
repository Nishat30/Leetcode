class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int n=nums.size();
        vector<int> dp(n+1,1);
        vector<int> cnt(n+1,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                }else if(nums[prev]<nums[i] && 1+dp[prev]==dp[i]){
                    cnt[i]+=cnt[prev];//cnt store krega 
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                }
            }
        }
        int nos=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                nos+=cnt[i];
            }
        }
        return nos;
    }
};