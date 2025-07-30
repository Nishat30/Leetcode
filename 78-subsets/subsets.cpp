class Solution {
public:
    void solve(int idx,vector<int>& nums,vector<vector<int>>& ans,vector<int>& output){
        if(idx>=nums.size()){
            ans.push_back(output);
            return ;
        }
        output.push_back(nums[idx]);
        //take
        solve(idx+1,nums,ans,output);
        output.pop_back();
        solve(idx+1,nums,ans,output);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // int subset=1<<nums.size();
        vector<vector<int>> ans;
        // for(int i=0;i<subset;i++){
        //     vector<int> output;
        //     for(int j=0;j<nums.size();j++){
        //        if(i & (1<<j)) output.push_back(nums[j]);
        //     }
        //     ans.push_back(output);
        // }
        vector<int> output;
        solve(0,nums,ans,output);
        return ans;

    }
};