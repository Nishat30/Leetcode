class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int last[32] = {};
        for (int i = nums.size() - 1; i >= 0; i--){
            int maxIndex = i;
            for (int b = 0; b < 32; b++){
                if (nums[i] & (1 << b))
                    last[b] = i;
                else
                    maxIndex = max(maxIndex, last[b]);
            }
            nums[i] = maxIndex - i + 1;
        }
        return nums;
    }
};