class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]%2!=0 || mp[nums[i]]==1){
                return false;
            }
        }
        return true;
    }
};