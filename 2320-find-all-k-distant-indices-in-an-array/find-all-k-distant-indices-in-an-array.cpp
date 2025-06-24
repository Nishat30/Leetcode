class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        vector<int> solve;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                solve.push_back(i);
            }
        }

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<solve.size();j++){
                if(abs(i-solve[j])<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};