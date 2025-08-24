class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;
            
            // shrink window if more than 1 zero
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            
            // right - left = length of window minus one zero
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};
