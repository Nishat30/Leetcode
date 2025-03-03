//same as count partitions with given difference
// just here the desired_target=(total_sum-target)/2 
class Solution {
public:
    int find_ways(vector<int> &nums, int target){
        int n=nums.size();
        vector<int> prev(target+1,0), curr(target+1,0);
        if(nums[0]==0) prev[0]=2;
        else prev[0]=1;
        //num[0]=0
        if(nums[0]!=0 && nums[0]<=target) prev[nums[0]]=1;
        for(int idx=1;idx<n;idx++){
            for(int sum=0;sum<=target;sum++){
                int not_take=prev[sum];
                int take=0;
                if(nums[idx]<=sum){
                  take=prev[sum-nums[idx]];}
                curr[sum]=(take+not_take);
            }
            prev=curr;
        }
        return prev[target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //space optimise code
        int total_sum=0;
        for(int num:nums){
            total_sum+=num;
        }
        int desired_target=(total_sum-target)/2;
        if (total_sum - target < 0 || (total_sum - target) % 2 != 0)
            return 0;
        return find_ways(nums,desired_target);
    }
};