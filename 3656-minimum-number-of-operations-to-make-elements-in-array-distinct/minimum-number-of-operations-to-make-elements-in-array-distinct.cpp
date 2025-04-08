class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cnt=0;
         while (true) {
            mp.clear();
            bool hasDuplicate = false;
            for (int i : nums) {
                if (mp.find(i) != mp.end()) {
                    hasDuplicate = true;
                    break;
                }
                mp[i]++;
            }
            if (!hasDuplicate) break;
            nums.erase(nums.begin(), nums.begin() + min(3, (int)nums.size()));
            cnt++;
        }

        return cnt;
    }
};