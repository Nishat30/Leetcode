class Solution {
public:
    int solve(int idx,int target,vector<int>& nums){
        if(idx==nums.size()){
            return 0;
        }
        int cnt = 0;
        for (int j = idx + 1; j < nums.size(); j++) {
            if (abs(nums[idx] - nums[j]) == target) {
                cnt++;  
            }
        }
        return cnt + solve(idx + 1, target, nums);
    }
    int countKDifference(vector<int>& nums, int k) {
        return solve(0, k, nums);
    }
};