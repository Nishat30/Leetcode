class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[i];
        }
        int j=0;
        for(int i=nums.size()-k;i<nums.size();i++){
            nums[j]=ans[i];
            j++;
        }
        for(int i=0;i<nums.size()-k;i++){
            nums[j]=ans[i];
            j++;
        }
    }
};