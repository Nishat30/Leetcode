class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        //first decreasing ele from the right
        while (i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        //if i==0 then no smaller ele exist for swapping directly reverse and return the string
        if (i == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        //smallest ele from the right side wish is greater than i
        int j = nums.size() - 1;
        while (j >= i && nums[j] <= nums[i-1]) {
            j--;
        }
        //swap and reverse
        swap(nums[i-1], nums[j]);
        reverse(nums.begin() + i, nums.end());        
    }
};