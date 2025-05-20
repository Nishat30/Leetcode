class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (const auto& query : queries) {
            int li = query[0], ri = query[1];
            diff[li] -= 1;
            if (ri + 1 < n) {
                diff[ri + 1] += 1;
            }
        }

        int currentDecrement = 0;
        for (int i = 0; i < n; ++i) {
            currentDecrement += diff[i];
            if(nums[i]!=0){
            nums[i] += currentDecrement;}
        }

        for (int num : nums) {
            if (num > 0) {
                return false;
            }
        }

        return true;
    }
};