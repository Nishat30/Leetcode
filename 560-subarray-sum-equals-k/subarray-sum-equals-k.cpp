class Solution {
public:
    int solve(int start, vector<int>& nums, int k) {
        if (start >= nums.size()) return 0;
        
        int count = 0;
        int currentSum = 0;
        for (int i = start; i < nums.size(); i++) {
            currentSum += nums[i];
            if (currentSum == k) count++;
        }
        return count + solve(start + 1, nums, k);
    }

    int subarraySum(vector<int>& nums, int k) {
        return solve(0, nums, k);
    }
};
