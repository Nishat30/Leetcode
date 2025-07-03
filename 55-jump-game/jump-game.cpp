class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_idx=0;
        for(int i=0;i<nums.size();i++){
            if(i>max_idx) return false;
            max_idx=max(max_idx,i+nums[i]);
        }
        return true;
    }
};