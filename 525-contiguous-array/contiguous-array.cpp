class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int prefix = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                prefix--;
            else
                prefix++;

            if (mp.find(prefix) != mp.end()) {
                ans = max(ans, i - mp[prefix]);
            } else {
                mp[prefix] = i;
            }
        }

        return ans;
    }
};