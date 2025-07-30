class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subset=1<<nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<subset;i++){
            vector<int> output;
            for(int j=0;j<nums.size();j++){
               if(i & (1<<j)) output.push_back(nums[j]);
            }
            ans.push_back(output);
        }
        return ans;
    }
};