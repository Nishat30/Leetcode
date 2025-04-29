class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_ele = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int left = 0, count = 0;
        int n = nums.size();

        for (int right = 0; right < n; ++right) {
            if (nums[right] == max_ele) count++;

            while (count >= k) {
                ans += (n - right);  // all subarrays from [left...right] to [left...n-1] are valid
                if (nums[left] == max_ele) count--;
                left++;
            }
        }

        return ans;
    }
};