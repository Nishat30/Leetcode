class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //kyuki yha subset hai subsequence nhi 
        //same longest incresing subsequence wala logic lagega
        //just condition change hoga
        int n=nums.size();
        int last_index=0;
        int maxi=0;
        vector<int> dp(n,1),hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                last_index=i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last_index]);
        while(hash[last_index]!=last_index){
            last_index=hash[last_index];
            ans.push_back(nums[last_index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};