class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0, cnt = 0;
        mp[0] = 1; // VERY IMPORTANT
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(mp.count(sum - k)){
                cnt += mp[sum - k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
