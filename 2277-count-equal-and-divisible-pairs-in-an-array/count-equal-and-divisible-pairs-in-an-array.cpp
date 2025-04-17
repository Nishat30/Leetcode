class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int, vector<int>> mp;  // key = number, value = list of indices
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                for (int j : mp[nums[i]]) {
                    if ((i * j) % k == 0)
                        cnt++;
                }
            }
            mp[nums[i]].push_back(i);
        }
        return cnt;
    }
};